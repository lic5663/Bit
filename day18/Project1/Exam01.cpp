#include <Windows.h>
#include <tchar.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("First"); //�밡���� ǥ���. lp: long point, sz: string ���� zero(\0)�� Ŭ����


// C��� �Լ� ȣ�� �Ծ� : cdecl
// window API �Լ� ȣ�� �Ծ� : stdcall
// WINAPI: ȣ������ �ǹ��Ѵ�.
// �Լ����� �ڽ��� ������ ������������ ������. �Լ� ȣ���̶� ���������ӿ� ���ڰ��� �Ѱ��ִ� ���̴�.
// cdecl�� ���� ���� �������� ���������� ���ÿ� �־��ش�. ex) ADD(a,b,c) �ϸ� c b a ������ ���ÿ� ����
// ȣ���ڴ� caller ȣ����Ѱ� callee. caller�� callee�� ���ÿ� ���ڸ� �׾��ش�. ��� �װ� ��� ���ٰ��̳ĸ� ���Ѱ��� ȣ�� �Ծ��̴�.
// cdecl�� callee�� ���� ���ڸ� caller�� �������ش�. c���� �������� �Լ��� �����ؼ� callee�ʿ����� ���ڰ� ����� �𸥴�. caller�� ���� ������ �ȴ�.
// �׷��� ���ڰ��� �˰��ִ� caller�� �ð��� �ɸ��� ���������� callee�� ���������ӿ� �����ϴ� ���ڸ� �����Ѵ�.
// stdcall ����� ���ÿ� �״� ������ ���������� �������� ����� ������� �����Ƿ� callee�� ������ �����Ѵ�. 
// WINAPI��� ȣ�� �Ծ��� �־� stdcall���� ����Ѵ�. �������� cdecl������� ó���Ѵ�.
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR IpszCmdParam, int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASSEX WndClass;		// ������ ������ ����ü�� ���ǵǾ��ִ�. �ʿ��� ������ ���� ���̴�.
	g_hInst = hInstance;

	WndClass.cbClsExtra = 0;	// �Ⱦ� ����
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// ��׶���� �귯�� �ڵ�. ������� ������ �������̳�.
																	// GetStockObject ������ �����ϴ� ��Ҹ� ������ ��� ����ϴ� �Լ�
																	// HBRUSH�� casting�Ѵ�.
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = WndProc;					// lp:������ fn:�Լ� -> �Լ�������. ���������� WndProc�� ����. 
	WndClass.lpszClassName = lpszClass;
	WndClass.lpszMenuName = NULL;					// �޴� �ȸ���
	WndClass.style = CS_HREDRAW | CS_VREDRAW;		// ������ ����� redaw�ض�. 
	WndClass.hIconSm = 0;							// ������������ �Ⱦ���.
	WndClass.cbSize = sizeof(WNDCLASSEX);			// ������ �񱳷� wndclass���� wndclassex���� �˷��� ũ�� ������ �ش�.
	RegisterClassEx(&WndClass);						// wndclassex�Ἥ ���⵵ ex����.
	// ���� ��� (������ Ŭ������, Ÿ��Ʋ�� ǥ�ø�, ������ ��Ÿ��, ������ ��ġ, ũ�� , �θ������� �ڵ�, �����쿡�� ����� �޴��ڵ�, ������ ���� ��ü, Ư������)
	// ATOM CreateWindow(laszClassName, laszWindowName, dwStyle, x, y ,nWidth, nHeight, hwndParent, hmenu, hInst, lpvParam)
	// ATOM : ������ �������� �����ϴ� ���¸� ����.
	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, (HMENU)NULL, hInstance, NULL);
	// ��ϵ� ������ ����
	ShowWindow(hWnd, nCmdShow);


	// ������� �޼��� �帮�� ����. �ܺο��� �޼����� ���� �׿� ���� �ൿ. 
	// System Queue�� ��� �̺�Ʈ�� �� ���´�. (Ű����, ���콺 ��) �� ���ø����̼Ǹ��� �����尡 �����ϴµ� ������� ������ ť�� ������.
	// system queue���� Thread Queue�� �޽����� �ѱ��.
	while (GetMessage(&Message, NULL, 0, 0))	// �ܺ� �̺�Ʈ�� ��� �޾��ش�.
	{
		//GetMessage�� WM_QUIT�� ������ ���� 0���� ��ȯ. 
		TranslateMessage(&Message);
		DispatchMessage(&Message);	// ������ �޼����� ���ڷ� �ѱ��. �Ʒ��� iMessage���ڷ� �Ѱ��ش�.
	}
	return (int)Message.wParam;	
}

// ȣ�� �Ծ� CALLBACK. stdcall��. ���ο��� ȣ����ؼ� ����.
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	// win32���� �ϴ°� �޼����� ���� ������ case�� �ۼ��ؼ� �̺�Ʈ�� ó���ϴ� �����̴�.
	switch (iMessage)
	{
	case WM_DESTROY:
		PostQuitMessage(0);	// ���� �޼����� ������. Ư���� ������ ������ �� �κ��� �ݵ�� �־��ش�.
		return 0;
	}
	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}

// Boiler Plate : ���Ϸ� ����. ������ �������� ���� ���� �ɸ�
// �� �κ��� �׷� �����̶�� ����ȴ�. p22