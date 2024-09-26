#include <Windows.h>
#include <thread>
#include <stdio.h>
#include <iostream>
#include <winsock.h>

#include "LogitechSteeringWheelLib.h"

#pragma comment(lib, "ws2_32lib")
#pragma comment(lib, "LogitechSteeringWheelLib.lib")

using namespace std;

LRESULT CALLBACK WindowProc(
	_In_ HWND hwnd,
	_In_ UINT uMsg,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam
);

int CALLBACK WinMain(
	_In_ HINSTANCE hInstance,
	_In_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nCmdShow
) {

	TCHAR cls_Name[] = "My Class";

	WNDCLASS wc = { sizeof(WNDCLASS) };
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.lpfnWndProc = WindowProc;
	wc.lpszClassName = cls_Name;
	wc.hInstance = hInstance;
	wc.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClass(&wc);

	HWND hwnd = CreateWindow(
		cls_Name,
		L"hello",
		WS_OVERLAPPEDWINDOW,
		38,
		20,
		500,
		500,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	if (hwnd == NULL) {
		return 0;
	}

}