#include <windows.h>
#include <tchar.h>

#define MAX_LOADSTRING 100
TCHAR szTitle[MAX_LOADSTRING] = _TEXT("First Sample"); // 제목 표시줄
TCHAR szWindowClass[MAX_LOADSTRING] = _TEXT("BIT");    // 기본 창 클래스

ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = DefWindowProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = 0;
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = 0;
	return RegisterClassEx(&wcex);
}

HWND InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;
	hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);
	if (!hWnd) {
		return 0;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return hWnd;
}

// 윈도우 구조체 들고와서 실시간 변경
int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrev, LPTSTR IpCmdLine, int nShowCmd)
{
	MyRegisterClass(hInst);

	HWND hwnd = InitInstance(hInst, nShowCmd);

	if (hwnd == 0)
	{
		return FALSE;
	}

	MessageBox(0, TEXT("실시간 정보 수정"), TEXT("First"), MB_OK);
	SetClassLongPtr(hwnd, GCLP_HBRBACKGROUND, (LONG)GetStockObject(DKGRAY_BRUSH));
	InvalidateRect(hwnd, NULL, TRUE);
	MessageBox(0, TEXT("Hello,API"), TEXT("First"), MB_OK);

	//실시간 클래스 정보 획득
	TCHAR temp[126];
	// GetClassLongPtr : 32bit  알파 B G R 의 32bit로 구성. bit shift로 연산해서 값들을 가져온다
	DWORD flag = GetClassLongPtr(hwnd, GCLP_HBRBACKGROUND);
	wsprintf(temp, _TEXT("R :%d, G :%d, B :%d"), GetRValue(flag), GetGValue(flag), GetBValue(flag));
	MessageBox(0, temp, TEXT("획득정보"), MB_OK);
	return 0;

}