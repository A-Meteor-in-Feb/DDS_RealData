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

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
}

int main(int argc, char* argv[]) {

    //using namespace application;

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
        wc.lpszClassName = "PLEASE!!!! SUCCESS!!! I don't want to DEBUG!!!";
        RegisterClass(&wc);
        HWND hwnd = CreateWindowEx(
            0,
            "PLEASE!!!! SUCCESS!!! I don't want to DEBUG!!!",
            "PLEASE!!!! SUCCESS!!! I don't want to DEBUG!!!",
            WS_OVERLAPPEDWINDOW,
            38, 20, 50, 50,
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

        initControllers();

        if (!shutdown_requested) {
            MSG msg = {};
            if (GetMessage(&msg, NULL, 0, 0)) { //while()
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
            std::thread tele_publisher(run_publisher_application);
            std::thread tele_subscriber(run_subscriber_application);

            tele_publisher.join();
            tele_subscriber.join();
        }
        else {
            DWORD ProcessId;
            HANDLE hProcess;
            if (GetWindowThreadProcessId(hwnd, &ProcessId) != 0) {
                hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, ProcessId);
                if (hProcess != NULL) {
                    TerminateProcess(hProcess, 0);
                }
            }
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


    dds::domain::DomainParticipant::finalize_participant_factory();

    return EXIT_SUCCESS;
}
