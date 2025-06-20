#include <string>
#include <locale>
#include <codecvt>
#include <bitset>
#include <iostream>
#include <thread>
#include <chrono>

#include <dds/pub/ddspub.hpp>
#include <dds/sub/ddssub.hpp>
#include <rti/util/util.hpp>      
#include <rti/config/Logger.hpp>  

#include "application.hpp"  
#include "data.hpp"
#include "partitionName.hpp"
#include "TimeStampLogger.h"

#include "LogitechSteeringWheelLib.h"

#pragma comment(lib, "LogitechSteeringWheelLib.lib")

#define MAX_NUMBER_OF_CONTROLLERS 5

wchar_t name[256];
int wheelIndex = -1;
int joystickIndex = -1;

DIJOYSTATE2* steeringWheel_state;
DIJOYSTATE2* joyStick_state;

int count_sentMsg = 200;


LRESULT CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam) {
    switch (message) {

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    default:
        return ::DefWindowProc(hwnd, message, wparam, lparam);
    }

}


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


void publisher_control_domain(int& tele, std::string& control_partition_name) {

    //const std::string filename1 = "tele_steeringWheel.txt";
    //const std::string filename2 = "tele_joystick.txt";
    std::this_thread::sleep_for(std::chrono::microseconds(10000000));
    std::this_thread::sleep_for(std::chrono::microseconds(10000000));
    std::this_thread::sleep_for(std::chrono::microseconds(10000000));
    std::string tele_id = "tele" + std::to_string(tele);

    std::string name = control_partition_name;
    std::cout << "start running publisher, partition: " << name << std::endl;

    HINSTANCE hInstance = GetModuleHandle(NULL);
    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = "Name";
    RegisterClass(&wc);
    HWND hwnd = CreateWindowEx(
        0,
        "Name",
        "Name",
        WS_OVERLAPPEDWINDOW,
        40, 20, 50, 50,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    if (hwnd == NULL) {
        std::cerr << "Failed to create a Window" << std::endl;
        return;
    }

    ShowWindow(hwnd, SW_SHOW);
    SetForegroundWindow(hwnd);

    MSG msg = {};
    if (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    initControllers();

    LogiPlayLeds(wheelIndex, 4, 1, 6);
    LogiSetOperatingRange(wheelIndex, 900);

    int control_domain = 1;

    dds::domain::DomainParticipant control_participant(control_domain);

    dds::pub::qos::PublisherQos pub_qos;

    dds::core::StringSeq partition_name{ name };

    pub_qos << dds::core::policy::Partition(partition_name);

    dds::pub::Publisher tele_publisher(control_participant, pub_qos);

    dds::topic::Topic< ::steeringWheel_data> steeringWheel_topic(control_participant, "steeringWheel_topic");
    dds::topic::Topic< ::joyStick_data> joyStick_topic(control_participant, "joyStick_topic");

    dds::pub::DataWriter< ::steeringWheel_data> steeringWheel_writer(tele_publisher, steeringWheel_topic);
    dds::pub::DataWriter< ::joyStick_data> joyStick_writer(tele_publisher, joyStick_topic);

    std::string timestamp;
    const auto frame_duration = std::chrono::milliseconds(33);

    while (count_sentMsg > 0) {

        auto start_time = std::chrono::steady_clock::now();

        if (GetKeyState('Q') < 0) {
            break;
        }

        //then, transmit the data...
        if (LogiUpdate()) {

            try {

                steeringWheel_state = LogiGetState(wheelIndex);
                joyStick_state = LogiGetState(joystickIndex);

                if (steeringWheel_state) {

                    //std::cout << "Detected: controller." << std::endl;

                    std::bitset<32> wheelButtons = getCombinedButtons(steeringWheel_state);

                    //Data needed to transmit
                    long sw_lX = steeringWheel_state->lX;
                    long sw_lY = steeringWheel_state->lY;
                    long sw_lRz = steeringWheel_state->lRz;
                    long sw_rglSlider_0 = steeringWheel_state->rglSlider[0];
                    unsigned long sw_buttons = wheelButtons.to_ulong();

                    //I think you initialize it here will cause some problems.
                    ::steeringWheel_data steeringWheel_data(sw_lX, sw_lY, sw_lRz, sw_rglSlider_0, sw_buttons);
                    steeringWheel_writer.write(steeringWheel_data);

                    timestamp = TimestampLogger::getTimestamp();
                    //TimestampLogger::writeToFile(filename1, timestamp);
                    //std::cout << "s data: " << steeringWheel_data << std::endl;
                    std::cout << "publish steering wheel data at: " << timestamp << std::endl;


                }
                else {
                    std::cout << "controller is nullptr" << std::endl;
                }

                if (joyStick_state) {

                    //std::cout << "Detected: JoyStick." << std::endl;

                    std::bitset<32> joyButtons = getBitwiseButtons(joyStick_state, 32);

                    long js_lX = joyStick_state->lX;
                    long js_lZ = joyStick_state->lZ;
                    long js_lRx = joyStick_state->lRx;
                    long js_lRy = joyStick_state->lRy;
                    long js_lRz = joyStick_state->lRz;
                    unsigned long js_buttons = joyButtons.to_ulong();
                    long js_rglSlider[2] = { joyStick_state->rglSlider[0], joyStick_state->rglSlider[1] };

                    //I think you initialize it here will cause some problems.
                    ::joyStick_data joyStick_data(js_lX, js_lZ, js_lRx, js_lRy, js_lRz, js_buttons, { js_rglSlider[0], js_rglSlider[1] });
                    joyStick_writer.write(joyStick_data);

                    timestamp = TimestampLogger::getTimestamp();
                    //TimestampLogger::writeToFile(filename2, timestamp);
                    //std::cout << "j data: " << joyStick_data << std::endl;
                    std::cout << "publish joystick data at: " << timestamp << std::endl;

                }
                else {
                    std::cout << "controller is nullptr" << std::endl;
                }

            }
            catch (const std::exception& e) {
                std::cerr << "Standard Exception: " << e.what() << std::endl;
            }
            catch (...) {
                std::cerr << "Unknown Error" << std::endl;
            }

            count_sentMsg -= 1;

            auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start_time);
            if (elapsed_time < frame_duration) {
                std::this_thread::sleep_for(std::chrono::milliseconds(frame_duration - elapsed_time)); // ~30Hz
            }
        }
    }

    std::cout << "publish all data" << std::endl;

    //PostMessage(HWND_BROADCAST, WM_DESTROY, 0, 0);
}