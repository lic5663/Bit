#include <windows.h>
#include <tchar.h>
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);
		Rectangle(hdc, 100, 100, 200, 200);

		SetMapMode(hdc, MM_LOMETRIC);
		HPEN pen = CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
		HPEN old = (HPEN)SelectObject(hdc, pen);
		Rectangle(hdc, 0, 0, 100, -100);
		DeleteObject(SelectObject(hdc, old));

		SetMapMode(hdc, MM_HIMETRIC);
		pen = CreatePen(PS_SOLID, 5, RGB(0, 255, 0));
		old = (HPEN)SelectObject(hdc, pen);
		Rectangle(hdc, 0, 0, 100, -100);
		DeleteObject(SelectObject(hdc, old));

		SetMapMode(hdc, MM_LOENGLISH);
		pen = CreatePen(PS_SOLID, 5, RGB(0, 0, 255));
		old = (HPEN)SelectObject(hdc, pen);
		Rectangle(hdc, 0, 0, 100, -100);
		DeleteObject(SelectObject(hdc, old));

		SetMapMode(hdc, MM_HIENGLISH);
		pen = CreatePen(PS_SOLID, 5, RGB(0, 122, 122));
		old = (HPEN)SelectObject(hdc, pen);
		Rectangle(hdc, 0, 0, 100, -100);
		DeleteObject(SelectObject(hdc, old));

		SetMapMode(hdc, MM_TWIPS);
		pen = CreatePen(PS_SOLID, 5, RGB(122, 0, 122));
		old = (HPEN)SelectObject(hdc, pen);
		Rectangle(hdc, 0, 0, 100, -100);
		DeleteObject(SelectObject(hdc, old));

		
		EndPaint(hwnd, &ps);
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