#include <windows.h>
#include <tchar.h>
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	static POINTS start, end;
	switch (msg)
	{
	case WM_LBUTTONDOWN:
		start = end = MAKEPOINTS(lParam);
		SetCapture(hwnd);
		return 0;

	case WM_LBUTTONUP:
		if (GetCapture() == hwnd)
		{
			ReleaseCapture();
			// �������� R2_COPYPEN���� �׷��� ��
			HDC hdc = GetDC(hwnd);
			SelectObject(hdc, GetStockObject(NULL_BRUSH));
			Rectangle(hdc, start.x, start.y, end.x, end.y);
			ReleaseDC(hwnd, hdc);
		}
		return 0;

	case WM_MOUSEMOVE:
		if (GetCapture() == hwnd)
		{
			POINTS pt = MAKEPOINTS(lParam);
			HDC hdc = GetDC(hwnd);
			// ��ũ�� ���� �� ���� ������ �Ѵ�.
			// NOTXOR : �Ȱ������� �κ��� 
			SetROP2(hdc, R2_NOTXORPEN);

			// NULL_BRUSH : ���� ������ ����
			// �κ귯���� ���ΰ� ����.

			SelectObject(hdc, GetStockObject(NULL_BRUSH));
			Rectangle(hdc, start.x, start.y, end.x, end.y);
			Rectangle(hdc, start.x, start.y, pt.x, pt.y);
			end = pt;
			ReleaseDC(hwnd, hdc);
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