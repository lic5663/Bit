#include <windows.h>
#include <tchar.h>
#include "resource1.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	static HCURSOR h1 = LoadCursorFromFile(TEXT("C:\\windows\\cursors\\aero_arrow.cur"));
	static HCURSOR h2 = LoadCursorFromFile(TEXT("C:\\windows\\cursors\\aero_pen.cur"));
	static RECT rc = { 100,100,300,300 }; // Ŭ���̾�Ʈ ��ǥ.
	switch (msg)
	{
	case WM_SETCURSOR:
	{
		int code = LOWORD(lParam);  // hit test code�� ��� �ִ�.
		POINT pt;
		GetCursorPos(&pt);          // ���� Ŀ���� ��ġ(��ũ�� ��ǥ)
		ScreenToClient(hwnd, &pt); // ��ũ�� ��ǥ�� Ŭ���� ��Ʈ ��ǥ��..
		// Ŭ���̾�Ʈ �ȿ����� Ư����ġ������ �ٸ� Ŀ���� ����ϴ� ���.
		if (code == HTCLIENT && PtInRect(&rc, pt))
		{
			SetCursor(LoadCursor(0, IDC_ARROW));
			return TRUE;
		}
		if (code == HTLEFT || code == HTRIGHT)
		{
			SetCursor(h2);
			return TRUE; // Ŀ���� ������ ��� TRUE ����
		}
		else if (code == HTTOP || code == HTBOTTOM)
		{
			SetCursor(h1);
			return TRUE;
		}
	}

	case WM_LBUTTONDOWN:
	{
		HDC hdc = GetDC(hwnd);
		HDC memDC = CreateCompatibleDC(hdc);
		HBITMAP hBitmap = LoadBitmap(GetModuleHandle(0), MAKEINTRESOURCE(IDB_BITMAP1));
		BITMAP bm;
		HICON hIcon = LoadIcon(GetModuleHandle(0), MAKEINTRESOURCE(IDI_ICON1));

		GetObject(hBitmap, sizeof(bm), &bm);
		SelectObject(memDC, hBitmap);
		TextOut(memDC, 5, 5, TEXT("LoadBitmap���� ���"), 15);
		POINTS pt = MAKEPOINTS(lParam);
		BitBlt(hdc, pt.x, pt.y, bm.bmWidth, bm.bmHeight, memDC, 0, 0, SRCCOPY);
		DrawIcon(hdc, pt.x, pt.y, hIcon);
		DeleteDC(memDC);
		ReleaseDC(hwnd, hdc);
		DeleteObject(hBitmap);
	}
	return 0;

	case WM_RBUTTONDOWN:
	{
		HDC hdc = GetDC(hwnd);
		HDC memDC = CreateCompatibleDC(hdc);
		HBITMAP hBitmap = (HBITMAP)LoadImage(0, TEXT("bbcat.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		BITMAP bm;

		GetObject(hBitmap, sizeof(bm), &bm);
		SelectObject(memDC, hBitmap);
		TextOut(memDC, 5, 5, TEXT("LoadImage�� ���"), 13);
		POINTS pt = MAKEPOINTS(lParam);
		BitBlt(hdc, pt.x, pt.y, bm.bmWidth, bm.bmHeight, memDC, 0, 0, SRCCOPY);
		DeleteDC(memDC);
		ReleaseDC(hwnd, hdc);
		DeleteObject(hBitmap);
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
	wc.hIcon = LoadIcon(hInst, MAKEINTRESOURCE(IDI_ICON1));
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