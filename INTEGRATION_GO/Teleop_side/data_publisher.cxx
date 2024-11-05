#include <iostream>

#include <dds/pub/ddspub.hpp>
#include <rti/util/util.hpp>      
#include <rti/config/Logger.hpp> 

#include <string>
#include <locale>
#include <codecvt>
#include <Windows.h>
#include <bitset>

#include "data.hpp"
#include "application.hpp"


void run_publisher_application();
void initControllers();
void run_subscriber_application();

std::thread tele_publisher;
std::thread tele_subscriber;
bool is_running = false;

HWND hwndReceivedTextDisplay;
HWND hwndSentTextDisplay;
std::string received_data = "No data received yet";
std::string sent_data = "No data sent yet";


void signal_handler(int signal) {
    if (signal == SIGINT) {
        is_running = false;
    }
}


void update_Recieved_text_display(std::string received_data) {
    std::string display_text = "Received Data: \n" + received_data;
    SetWindowText(hwndReceivedTextDisplay, display_text.c_str());
}

void update_Sent_text_display(std::string sent_data) {
    std::string display_text = "Sent Data: \n" + sent_data;
    SetWindowText(hwndSentTextDisplay, display_text.c_str());
}


LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    //Destorying Window...
    case WM_DESTROY:
        //Post a WM_QUIT message to the message queue, prompting the GetMessage function to return 0
        //ending the message loop.
        PostQuitMessage(0);
        std::raise(SIGINT);
        if (tele_publisher.joinable()) {
            tele_publisher.join();
        }
        if (tele_subscriber.joinable()) {
            tele_subscriber.join();
        }
        return 0;

    case WM_COMMAND:

        if (LOWORD(wParam) == 1) {  // Begin button clicked
            if (!is_running) {
                is_running = true;
                shutdown_requested = false;
                tele_subscriber = std::thread(run_subscriber_application);
                tele_publisher = std::thread(run_publisher_application);
                
            }
        }

        else if (LOWORD(wParam) == 2) {  // Stop button clicked
            if (is_running) {
                std::raise(SIGINT);
                shutdown_requested = true;
                tele_subscriber.join();
                tele_publisher.join();
                dds::domain::DomainParticipant::finalize_participant_factory();
            }
        }
        break;

    default:
        //Leave the messages we don't process to the operating system for default processing.
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
}

int main(int argc, char* argv[]) {

    // Parse arguments and handle control-C
    auto arguments = parse_arguments(argc, argv);
    if (arguments.parse_result == ParseReturn::exit) {
        return EXIT_SUCCESS;
    }
    else if (arguments.parse_result == ParseReturn::failure) {
        return EXIT_FAILURE;
    }
    setup_signal_handlers();

    // Sets Connext verbosity to help debugging
    rti::config::Logger::instance().verbosity(arguments.verbosity);

    try {

        HINSTANCE hInstance = GetModuleHandle(NULL);
        WNDCLASS wc = {};
        wc.lpfnWndProc = WindowProc;
        wc.hInstance = hInstance;
        wc.lpszClassName = "Teleoperation Station - Data";
        RegisterClass(&wc);
        HWND hwnd = CreateWindowEx(
            0,
            "Teleoperation Station - Data",
            "Teleoperation Station - Data",
            WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT, CW_USEDEFAULT, 650, 650,
            NULL,
            NULL,
            hInstance,
            NULL
        );
        if (hwnd == NULL) {
            std::cerr << "Failed to create window." << std::endl;
            return 0;
        }

        ShowWindow(hwnd, SW_SHOW);
        SetForegroundWindow(hwnd);

        // Create Begin and Stop buttons
        HWND hwndButtonBegin = CreateWindow(
            "BUTTON", "Begin",
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            230, 10, 80, 30,
            hwnd, (HMENU)1, hInstance, NULL
        );


        HWND hwndButtonStop = CreateWindow(
            "BUTTON", "Stop",
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            330, 10, 80, 30,
            hwnd, (HMENU)2, hInstance, NULL
        );

        // Create a text display for showing data

        hwndReceivedTextDisplay = CreateWindow(
            "STATIC", "Waiting to receive data...",
            WS_VISIBLE | WS_CHILD | SS_LEFT,
            10, 60, 300, 500,
            hwnd, NULL, hInstance, NULL
        );

        hwndSentTextDisplay = CreateWindow(
            "STATIC", "Waiting to send data ...",
            WS_VISIBLE | WS_CHILD | SS_LEFT,
            320, 60, 300, 500,
            hwnd, NULL, hInstance, NULL
        );


        initControllers();

        MSG msg = {};
        while (GetMessage(&msg, NULL, 0, 0)) { //while()
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

    }
    catch (const std::exception& ex) {
        // This will catch DDS exceptions
        std::cerr << "Exception in run_publisher_application(): " << ex.what()
            << std::endl;
        return EXIT_FAILURE;
    }
    catch (...) {
        std::cerr << "Unknown Error :(" << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
