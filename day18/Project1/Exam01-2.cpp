#include <windows.h>
#include <tchar.h>

int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrev, LPTSTR IpCmdLine, int nShowCmd)
{
	// �۾�ǥ����
	HWND hWnd = FindWindow(TEXT("Shell_TrayWnd"), 0);
	if (IsWindowVisible(hWnd))
	{
		MessageBox(hWnd, _TEXT("�۾��ٰ� ������� ������ �����ٰſ���"), TEXT("�ź��� ����"), MB_ICONQUESTION);
		ShowWindow(hWnd, SW_HIDE);
		MessageBox(hWnd, _TEXT("¥��"), TEXT("�ź��� ����"), MB_OK);
	}
		
	else
	{
		MessageBox(hWnd, _TEXT("�۾��ٰ� ��Ÿ���� ������ �����ٰſ���"), TEXT("�ź��� ����"), MB_ICONASTERISK);
		ShowWindow(hWnd, SW_SHOW);
		MessageBox(hWnd, _TEXT("¥��"), TEXT("�ź��� ����"), MB_OK);
	}
		
	return 0;
}