#include <windows.h>
#include <tchar.h>

#define MAX_LOADSTRING 100
TCHAR szTitle[MAX_LOADSTRING] = _TEXT("First Sample"); // ���� ǥ����
TCHAR szWindowClass[MAX_LOADSTRING] = _TEXT("BIT");    // �⺻ â Ŭ����

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

// ������ ����ü ���ͼ� �ǽð� ����
int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrev, LPTSTR IpCmdLine, int nShowCmd)
{
	MyRegisterClass(hInst);

	HWND hwnd = InitInstance(hInst, nShowCmd);

	if (hwnd == 0)
	{
		return FALSE;
	}

	MessageBox(0, TEXT("�ǽð� ���� ����"), TEXT("First"), MB_OK);
	SetClassLongPtr(hwnd, GCLP_HBRBACKGROUND, (LONG)GetStockObject(DKGRAY_BRUSH));
	InvalidateRect(hwnd, NULL, TRUE);
	MessageBox(0, TEXT("Hello,API"), TEXT("First"), MB_OK);

	//�ǽð� Ŭ���� ���� ȹ��
	TCHAR temp[126];
	// GetClassLongPtr : 32bit  ���� B G R �� 32bit�� ����. bit shift�� �����ؼ� ������ �����´�
	DWORD flag = GetClassLongPtr(hwnd, GCLP_HBRBACKGROUND);
	wsprintf(temp, _TEXT("R :%d, G :%d, B :%d"), GetRValue(flag), GetGValue(flag), GetBValue(flag));
	MessageBox(0, temp, TEXT("ȹ������"), MB_OK);
	return 0;

}