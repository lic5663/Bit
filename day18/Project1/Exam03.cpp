#include <windows.h>
#include <tchar.h>
#define WM_MYMESSAGE WM_USER+100
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_MYMESSAGE:
	{
		TCHAR buf[20];
		wsprintf(buf, TEXT("%d , %d"), wParam, lParam);
		MessageBox(hwnd, buf, TEXT(""), MB_ICONWARNING);
		return 0;
	}

	case WM_LBUTTONDOWN:
	{
		static int i = 10;
		HDC hdc = GetDC(hwnd);
		Rectangle(hdc, i, i, i+90, i+90);
		i += 3;
		ReleaseDC(hwnd, hdc);

		POINT CursorPos;
		GetCursorPos(&CursorPos);
		SendMessage(hwnd, WM_MYMESSAGE, (&CursorPos)->x, (&CursorPos)->y);
		return 0;

	}
	return 0;

	case WM_RBUTTONDOWN:
	{
		static int j = 1000;
		HDC hdc = GetDC(hwnd);
		Rectangle(hdc, j, j, j + 90, j + 90);
		j -= 3;
		ReleaseDC(hwnd, hdc);
	}
	return 0;

	case WM_MBUTTONDOWN:
	{
		static int k = 0;
		HDC hdc = GetDC(hwnd);
		Rectangle(hdc, 200+k, 200+k, 500-k, 500-k);
		k += 4;
		ReleaseDC(hwnd, hdc);
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