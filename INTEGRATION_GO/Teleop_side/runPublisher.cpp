
#include <iostream>

#include <dds/pub/ddspub.hpp>
#include <rti/util/util.hpp>      
#include <rti/config/Logger.hpp>  

#include "application.hpp"
#include "data.hpp"

#include <string>
#include <locale>
#include <codecvt>
#include <Windows.h>
#include <bitset>

#include "LogitechSteeringWheelLib.h"

#pragma comment(lib, "LogitechSteeringWheelLib.lib")

#define MAX_NUMBER_OF_CONTROLLERS 5


void update_Sent_text_display(std::string sent_data);


wchar_t name[256];
int wheelIndex = -1;
int joystickIndex = -1;

DIJOYSTATE2* steeringWheel_state;
DIJOYSTATE2* joyStick_state;

std::string wstringToString(const std::wstring& wstr) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    return converter.to_bytes(wstr);
}

std::bitset<32> getBitwiseButtons(DIJOYSTATE2* state, int max_buttons) {
    std::bitset<32> buttons;
    for (int i = 0; i < max_buttons; ++i) {
        if (state && (state->rgbButtons[i] & 0x80)) {
            buttons.set(i);
        }
    }

    return buttons;
}

std::bitset<32> getCombinedButtons(DIJOYSTATE2* state) {
    std::bitset<32> buttons = getBitwiseButtons(state, 24);
    if (state) {
        switch (state->rgdwPOV[0]) {
        case 0: buttons.set(24); break;      //up
        case 4500: buttons.set(25); break;   //up-right
        case 9000: buttons.set(26); break;   //right
        case 13500: buttons.set(27); break;  //down-right
        case 18000: buttons.set(28); break;  //down
        case 22500: buttons.set(29); break;  //down-left
        case 27000: buttons.set(30); break;  //left
        case 31500: buttons.set(31); break;  //up-left
        default: break;                      //no direction
        }
    }
    return buttons;

}

void initControllers() {

    while (!LogiSteeringInitialize(true) && !shutdown_requested) {
        std::cerr << "Error - couldn't detect any controller. Are you running as administrator?" << std::endl;
        LogiUpdate();
        Sleep(100);
    }

    if (!shutdown_requested) {

        for (int i = 0; i < MAX_NUMBER_OF_CONTROLLERS; i++) {

            if (LogiIsConnected(i)) {
                LogiGetFriendlyProductName(i, name, sizeof(name));
                std::wstring wname(name);
                std::string nameStr = wstringToString(wname);

                if (nameStr.find("wheel") != std::string::npos || nameStr.find("Wheel") != std::string::npos) {
                    wheelIndex = i;
                    std::cout << "Wheel detected at index: " << wheelIndex << std::endl;
                }
                else if (nameStr.find("stick") != std::string::npos || nameStr.find("Stick") != std::string::npos) {
                    joystickIndex = i;
                    std::cout << "JoyStick detected at index: " << joystickIndex << std::endl;
                }
            }
        }
    }

}


void run_publisher_application() {

    LogiPlayLeds(wheelIndex, 4, 1, 6);
    LogiSetOperatingRange(wheelIndex, 900);

    int domain_id = 0;

    dds::domain::DomainParticipant participant(domain_id);
    dds::pub::Publisher teleop_publisher(participant);

    dds::topic::Topic< ::steeringWheel_data> steeringWheel_topic(participant, "steeringWheel_topic");
    dds::topic::Topic< ::joyStick_data> joyStick_topic(participant, "joyStick_topic");

    dds::pub::DataWriter< ::steeringWheel_data> steeringWheel_writer(teleop_publisher, steeringWheel_topic);
    dds::pub::DataWriter < ::joyStick_data> joyStick_writer(teleop_publisher, joyStick_topic);

    ::steeringWheel_data steeringWheel_data;
    ::joyStick_data joyStick_data;

    while (!shutdown_requested) {

        if (GetKeyState('Q') < 0) {
            shutdown_requested = true;
            break;
        }

        if (LogiUpdate()) {
            try {

                steeringWheel_state = LogiGetState(wheelIndex);
                joyStick_state = LogiGetState(joystickIndex);

                if (steeringWheel_state && joyStick_state) {

                    std::cout << "Detected: controller and joystick." << std::endl;

                    std::bitset<32> wheelButtons = getCombinedButtons(steeringWheel_state);
                    std::bitset<32> joyButtons = getBitwiseButtons(joyStick_state, 32);

                    //Data needed to transmit
                    long sw_lX = steeringWheel_state->lX;
                    long sw_lY = steeringWheel_state->lY;
                    long sw_lRz = steeringWheel_state->lRz;
                    long sw_rglSlider_0 = steeringWheel_state->rglSlider[0];
                    unsigned long sw_buttons = wheelButtons.to_ulong();


                    long js_lX = joyStick_state->lX;
                    long js_lY = joyStick_state->lY;
                    long js_lZ = joyStick_state->lZ;
                    long js_lRx = joyStick_state->lRx;
                    long js_lRy = joyStick_state->lRy;
                    long js_lRz = joyStick_state->lRz;
                    unsigned long js_buttons = joyButtons.to_ulong();
                    long js_rglSlider[2] = { joyStick_state->rglSlider[0], joyStick_state->rglSlider[1] };


                    steeringWheel_data.lX(sw_lX);
                    steeringWheel_data.lY(sw_lY);
                    steeringWheel_data.lRz(sw_lRz);
                    steeringWheel_data.rglSlider_0(sw_rglSlider_0);
                    steeringWheel_data.buttons(sw_buttons);

                    joyStick_data.lX(js_lX);
                    joyStick_data.lY(js_lY);
                    joyStick_data.lZ(js_lZ);
                    joyStick_data.lRx(js_lRx);
                    joyStick_data.lRy(js_lRy);
                    joyStick_data.lRz(js_lRz);
                    joyStick_data.buttons(js_buttons);
                    joyStick_data.rglSlider({ js_rglSlider[0], js_rglSlider[1] });

                    steeringWheel_writer.write(steeringWheel_data);
                    joyStick_writer.write(joyStick_data);


                    std::cout << "Writing: steeringWheel_data & joyStick_data" << std::endl;
                }
                else if (steeringWheel_state && !joyStick_state) {
                    std::cout << "Detected: controller." << std::endl;

                    std::bitset<32> wheelButtons = getCombinedButtons(steeringWheel_state);

                    //Data needed to transmit
                    long sw_lX = steeringWheel_state->lX;
                    long sw_lY = steeringWheel_state->lY;
                    long sw_lRz = steeringWheel_state->lRz;
                    long sw_rglSlider_0 = steeringWheel_state->rglSlider[0];
                    unsigned long sw_buttons = wheelButtons.to_ulong();

                    steeringWheel_data.lX(sw_lX);
                    steeringWheel_data.lY(sw_lY);
                    steeringWheel_data.lRz(sw_lRz);
                    steeringWheel_data.rglSlider_0(sw_rglSlider_0);
                    steeringWheel_data.buttons(sw_buttons);

                    steeringWheel_writer.write(steeringWheel_data);

                    std::cout << "Writing: steeringWheel_data" << std::endl;

                }
                else if (!steeringWheel_state && joyStick_state) {
                    std::cout << "Detected: joystick." << std::endl;

                    std::bitset<32> joyButtons = getBitwiseButtons(joyStick_state, 32);

                    long js_lX = joyStick_state->lX;
                    long js_lY = joyStick_state->lY;
                    long js_lZ = joyStick_state->lZ;
                    long js_lRx = joyStick_state->lRx;
                    long js_lRy = joyStick_state->lRy;
                    long js_lRz = joyStick_state->lRz;
                    unsigned long js_buttons = joyButtons.to_ulong();
                    long js_rglSlider[2] = { joyStick_state->rglSlider[0], joyStick_state->rglSlider[1] };

                    joyStick_data.lX(js_lX);
                    joyStick_data.lY(js_lY);
                    joyStick_data.lZ(js_lZ);
                    joyStick_data.lRx(js_lRx);
                    joyStick_data.lRy(js_lRy);
                    joyStick_data.lRz(js_lRz);
                    joyStick_data.buttons(js_buttons);
                    joyStick_data.rglSlider({ js_rglSlider[0], js_rglSlider[1] });

                    joyStick_writer.write(joyStick_data);

                    std::cout << "Writing: joyStick_data" << std::endl;

                }
                else {
                    std::cerr << "Error: wheel_state or joy_state is nullptr" << std::endl;
                }


            }
            catch (const std::exception& e) {
                std::cerr << "Standard Exception: " << e.what() << std::endl;
            }
            catch (...) {
                std::cerr << "Unknown Error" << std::endl;
            }

            Sleep(33); // ~30Hz
        }

    }
}