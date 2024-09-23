#include <iostream>
#include <string>
#include <locale>
#include <codecvt>
#include <Windows.h>


#include "LogitechSteeringWheelLib.h"

#pragma comment(lib, "LogitechSteeringWheelLib.lib")

#define MAX_NUMBER_OF_CONTROLLERS 5

wchar_t name[256];
int wheelIndex = -1;
int joystickIndex = -1;

DIJOYSTATE2* wheel_state;
DIJOYSTATE2* joy_state;
/*
* DIJOYSTATE2:
* 
*/

std::string wstringToString(const std::wstring& wstr) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    return converter.to_bytes(wstr);
}

void initControllers() {
    /*
    * This function is for initializing the controller.
    */


    while (!LogiSteeringInitialize(true)) {
        /*
        * LogiSteeringInitialize():
        * This function makes sure the main window has come to foreground.
        * Then, if there isn't already another instance running makes necessary initializations.
        * 
        * Return - true, if the function succeeds.
        * Return - false, if the main window of your application has not come to foreground yet.
        *          This means that the window handler cannot be retrieved yet.
        */
        std::cerr << "Error - couldb't detect any controller." << std::endl;
        LogiUpdate();
        /*
        * LogiUpdat():
        * This function looks for the main window handler, if it has been found keeps forces and controller
        * connections up to date. It has to be called every frame of the application.
        * 
        * Return - true, if the function succeeds.
        * Return - false, if LogiSteeringInitialize() hasn't been called or it has been unable to find the
        *          main window handler.
        */
        Sleep(2000);
    }

    for (int i = 0; i < MAX_NUMBER_OF_CONTROLLERS; i++) {
        if (LogiIsConnected(i)) {
            /*
            * LogiIsConnected(const int index):
            * index: index of the game controller.
            *        Index 0 corresponds to the first game controller connected.
            *        Index 1 corresponds to the second game controller connnected.
            * This function checks if a game controller is connected at the specified index.
            * 
            * Return - true is a device is connected at the specified index, false otherwise.
            */

            LogiGetFriendlyProductName(i, name, sizeof(name));
            /*
            * LogiGetFriendlyProductName(const int index, wchar_t *buffer, int bufferSize)
            * index: index of the game controller
            * buffer: a pre-allocated wchar_t buffer that will contain the device name.
            * bufferSize: the size in bytes for the buffer.
            * 
            * Return - True, if it succeeds.
            * Return - Fasle, if there is an error in copying the name in the buffer.
            */

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


void handleConnection() {

    LogiPlayLeds(wheelIndex, 4, 1, 6);
    LogiSetOperatingRange(wheelIndex, 900);

    while (GetKeyState('Q') >= 0) {
        /*
        * GetKeyState(Key):
        * The return values are mainly divided into 2 cases:
        * 1. If the monitored key is not currently pressed (including both cases where it has never been pressed
        *    and just released), it returns 0 or 1 (the first time the program runs, it returns 0;
        *    after that, it alternates between 0 and 1 each time the key is released).
        * 2. If the monitored key is currently being hold down and has not been released, 
        *    it returns -127 or -128 (the first time the program runs, it returns -128;
        *    after that, it alternates between -127 and -128 each time the key is released).
        * In sum, when the return value is negative, the monitored key is being held down.
        * Otherwise, the key has just been released.
        */

        /*if (LogiUpdate()) {
            try {
                wheel_state = LogiGetState(wheelIndex);
                joy_state = LogiGetState(joystickIndex);
            }
        }*/
    }
}


int main(){

    initControllers();

    std::cout << "Hello World!\n";
}
