#include <windows.h>
#include <tchar.h>
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_LBUTTONDOWN:
	{
		HDC hdc = GetDC(hwnd);
		Rectangle(hdc, 120, 10, 210, 100);
		ReleaseDC(hwnd, hdc);
	}
	return 0;

	case WM_RBUTTONDOWN:
	{
		
		RECT r = { 120,10,210,100 };
		InvalidateRect(hwnd, &r, TRUE);
	}
	return 0;

	case WM_PAINT:
	{
		static int i = 0;
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);
		//HDC hdc = GetDC(hwnd); // begin이 flag를 0으로 해주므로 GetDC로 하면 무한 반복된다.
		Rectangle(hdc, 10+i, 10, 100+i, 100);
		EndPaint(hwnd, &ps);
		//ReleaseDC(hwnd, hdc);
		i += 10;
	}
	return 0;

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