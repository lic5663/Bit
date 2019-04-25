#include <windows.h>
#include <tchar.h>
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_LBUTTONDOWN:
	{
		BOOL bPresent = GetSystemMetrics(SM_MOUSEPRESENT);
		BOOL bWheel = GetSystemMetrics(SM_MOUSEWHEELPRESENT);
		int nBtn = GetSystemMetrics(SM_CMOUSEBUTTONS);
		int scx = GetSystemMetrics(SM_CXSCREEN);
		int scy = GetSystemMetrics(SM_CYSCREEN);

		TCHAR info[128];
		wsprintf(info, TEXT("%s %s is installed. (%d Buttons) \n"), (bWheel ? TEXT("Wheel") : TEXT("")), (bPresent ? TEXT("Mouse") : TEXT("No Mouse")), nBtn);
		TCHAR temp[64];
		wsprintf(temp, TEXT("\nScreen Resolution : %d * %d"), scx, scy);
		_tcscat(info, temp);

		MessageBox(NULL, info, TEXT(""), MB_OK);
	}

	case WM_CREATE:
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}

int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hprev, LPTSTR IpCmdLine, int nShowCmd)
{
	WNDCLASS wc;
	wc.cbWndExtra = 0;
	wc.cbClsExtra = 0;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.hCursor = LoadCursor(0, IDC_ARROW);
	wc.hIcon = LoadIcon(0, IDI_APPLICATION);
	wc.hInstance = hInst;
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = TEXT("First");
	wc.lpszMenuName = 0;
	wc.style = 0;

	RegisterClass(&wc);

	HWND hwnd = CreateWindowEx(0, TEXT("first"), TEXT("Hello"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, 0, 0, hInst, 0);
	ShowWindow(hwnd, SW_SHOW);
	UpdateWindow(hwnd);

	MSG msg;

	while (GetMessage(&msg, 0, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}