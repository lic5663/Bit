#include <windows.h>
#include <tchar.h>

int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrev, LPTSTR IpCmdLine, int nShowCmd)
{
	// 작업표시줄
	HWND hWnd = FindWindow(TEXT("Shell_TrayWnd"), 0);
	if (IsWindowVisible(hWnd))
	{
		MessageBox(hWnd, _TEXT("작업바가 사라지는 마술을 보여줄거에요"), TEXT("신비한 마술"), MB_ICONQUESTION);
		ShowWindow(hWnd, SW_HIDE);
		MessageBox(hWnd, _TEXT("짜란"), TEXT("신비한 마술"), MB_OK);
	}
		
	else
	{
		MessageBox(hWnd, _TEXT("작업바가 나타나는 마술을 보여줄거에요"), TEXT("신비한 마술"), MB_ICONASTERISK);
		ShowWindow(hWnd, SW_SHOW);
		MessageBox(hWnd, _TEXT("짜란"), TEXT("신비한 마술"), MB_OK);
	}
		
	return 0;
}