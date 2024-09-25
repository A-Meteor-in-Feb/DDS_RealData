#include <iostream>

#include <dds/pub/ddspub.hpp>
#include <rti/util/util.hpp>      // for sleep()
#include <rti/config/Logger.hpp>  // for logging

#include "application.hpp"  // for command line parsing and ctrl-c
#include "data.hpp"

#include <string>
#include <locale>
#include <codecvt>
#include <Windows.h>
#include <bitset>

#include "LogitechSteeringWheelLib.h"

#pragma comment(lib, "LogitechSteeringWheelLib.lib")

#define MAX_NUMBER_OF_CONTROLLERS 5

wchar_t name[256];
int wheelIndex = -1;
int joystickIndex = -1;

DIJOYSTATE2* wheel_state;
DIJOYSTATE2* joy_state;


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
    while (!LogiSteeringInitialize(true)) {
        std::cerr << "Error - couldb't detect any controller." << std::endl;
        LogiUpdate();
        Sleep(2000);
    }

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


void processData() {

    LogiPlayLeds(wheelIndex, 4, 1, 6);
    LogiSetOperatingRange(wheelIndex, 900);

    while (GetKeyState('Q') >= 0) {
        if (LogiUpdate()) {
            try {
                wheel_state = LogiGetState(wheelIndex);
                joy_state = LogiGetState(joystickIndex);
                if (wheel_state && joy_state) {
                    std::bitset<32> wheelButtons = getCombinedButtons(wheel_state);
                    std::bitset<32> joyButtons = getBitwiseButtons(joy_state, 32);

                    //Data needed to transmit
                    unsigned long wheel_buttons = wheelButtons.to_ulong();
                    long wheel_posX = wheel_state->lX;
                    long wheel_posY = wheel_state->lY;
                    long wheel_posZ = wheel_state->lZ;

                    unsigned long joy_buttons = joyButtons.to_ulong();
                    long joy_posX = joy_state->lX;
                    long joy_posY = joy_state->lY;
                    long joy_posZ = joy_state->lZ;
                    long joy_rotx = joy_state->lRx;
                    long joy_roty = joy_state->lRy;
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

    //Ensure proper shutdown of Logitech SDK
    LogiPlayLeds(wheelIndex, 0, 1, 6);
    LogiStopSpringForce(wheelIndex);
    LogiSteeringShutdown();
}


void run_publisher_application(unsigned int domain_id){

    dds::domain::DomainParticipant participant(domain_id);

    dds::topic::Topic< ::control_data> topic(participant, "Example control_data");

    dds::pub::Publisher publisher(participant);

    dds::pub::DataWriter< ::control_data> writer(publisher, topic);

    ::control_data data;
    
    while (!application::shutdown_requested) {
        // Modify the data to be written here
        data.lX(static_cast< int32_t>(1));
        data.lY(static_cast< int32_t>(1));
        data.lZ(static_cast< int32_t>(1));
        data.lRx(static_cast< int32_t>(1));
        data.lRy(static_cast< int32_t>(1));
        data.lRz(static_cast< int32_t>(1));
        data.buttons(1);

        std::cout << "Writing ::control_data" << std::endl;

        writer.write(data);

        // Send once every second
        rti::util::sleep(dds::core::Duration(1));
    }
}

int main(int argc, char *argv[]){

    using namespace application;

    auto arguments = parse_arguments(argc, argv);
    if (arguments.parse_result == ParseReturn::exit) {
        return EXIT_SUCCESS;
    } else if (arguments.parse_result == ParseReturn::failure) {
        return EXIT_FAILURE;
    }
    setup_signal_handlers();

    rti::config::Logger::instance().verbosity(arguments.verbosity);

    try {
        initControllers();
        processData();
        run_publisher_application(arguments.domain_id);
    } catch (const std::exception& ex) {
        std::cerr << "Exception in run_publisher_application(): " << ex.what() << std::endl;
        return EXIT_FAILURE;
    }
    catch (...) {
        std::cerr << "Unknown Error :(" << std::endl;
        return EXIT_FAILURE;
    }

    dds::domain::DomainParticipant::finalize_participant_factory();

    return EXIT_SUCCESS;
}
