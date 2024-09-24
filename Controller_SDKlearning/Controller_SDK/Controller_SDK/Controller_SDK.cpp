#include <iostream>
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
/*
* typedef struct DIJOYSTATE2{
*       Long lX;  //x-axis position
*       Long lY;  //y-axis position
*       Long lZ;  //z-axis position
*       Long lRx; //x-axis rotation
*       Long lRy; //y-axis rotation
*       Long lRz; //z-axis rotation
*       Long rglSlider[2]; //Position of two sliders
*       DWORD rgdwPOV[4];  //Position of up to four point-of-view hats
*       BYTE rgbButtons[128]; //State of 128 buttons
*       Long lVX; //velocity along the x-axis
*       Long lVY; //velocity along the y-axis
*       Long lVZ; //velocity along the z-axis
*       Long lVRx; //Angular velocity around the x-axis
*       Long lVRy; //Angular velocity around the y-axis
*       Long lVRz; //Angular velocity around the z-axis
*       Long rglVSlider[2]; //velocity of the two sliders
*       Long lAX; //acceleration along the x-axis
*       Long lAY; //acceleration along the y-axis
*       Long lAZ; //acceleration along the z-axis
*       Long lARx; //angular acceleration around the x-axis
*       Long lARy; //angular acceleration around the y-axis
*       Long lARz; //angular acceleration around the z-axis
*       Long rglASlider[2]; //Acceleration of the two sliders
*       Long lFX; //force along the x-axis
*       Long lFY; //force along the y-axis
*       Long lFZ; //force along the z-axis
*       Long lFRx; //torque around the x-axis
*       Long lFRy; //torque around the y-axis
*       Long lFRz; //torque around the z-axis
*       Long rglFSlider[2]; //force applied to the two sliders
* } DIJOYSTATE2;
*/


std::string wstringToString(const std::wstring& wstr) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    return converter.to_bytes(wstr);
}


std::bitset<32> getBitwiseButtons(DIJOYSTATE2* state, int max_buttons) {
    std::bitset<32> buttons;
    for (int i = 0; i < max_buttons; ++i) {
        if (state && (state->rgbButtons[i] & 0x80)) {
            /*
            * "state->rgbButtons[i] & 0x80":
            * This sentence is to check whether the ith button is pressed or not 
            * by checking the higest bit's value.
            */
            buttons.set(i);
            /*
            * This 32 bits buttons is to store the specific buttons that being pressed.
            */
        }
    }

    return buttons;
}


std::bitset<32> getCombinedButtons(DIJOYSTATE2* state) {
    std::bitset<32> buttons = getBitwiseButtons(state, 24);
    /*
    * We will use 24 buttons all together.
    * And use getBitwiseButtons() to get the used ones.
    */

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
    /*
    * Now, we use 32 buttons in total.
    */

    return buttons;

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

        if (LogiUpdate()) {
            try {
                wheel_state = LogiGetState(wheelIndex);
                joy_state = LogiGetState(joystickIndex);
                /*
                * LogiGetState(const int index):
                * This Function returns the state of the controller in the struct DIJOYSTATE2.
                * Use this if working with DirectInput from Microsoft windows, it requires:
                * dinput.h
                * index: index of the game controller
                * If not working with DirectInput, or can't include dinput.h, use: LogiGetStateENGINES
                */

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

                    /*
                    * TO-DO: 
                    *   1) Then send data
                    *   2) if (connection_ok) {
                    *           LogiPlayLeds(wheelIndex, 2, 1, 6); //Good connection
                    *           LogiPlaySpringForce(wheelIndex, int(0), 100, 25);
                    *      } else {
                    *           LogiPlayLeds(wheelIndex, 6, 1, 6); //Connection interrupt
                    *           LogiStopSpringForce(wheelIndex);
                    *      }
                    */

                } else {
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


int main(){

    try {
        initControllers();
        handleConnection();
    }
    catch (const std::exception& e) {
        std::cerr << "Standard Initialization Exception: " << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Unknown Error :(" << std::endl;
    }

    std::cout << "Hello World!\n";

    return 0;
}
