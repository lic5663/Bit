#include <Windows.h>
#include <stdio.h>
#define WM_MYMESSAGE WM_USER+100

void main()
{
	HWND hwnd = FindWindow(0, TEXT("Hello"));
	//int value = SendMessage(hwnd, WM_MYMESSAGE, 10, 20);
	BOOL b = PostMessage(hwnd, WM_MYMESSAGE, 10, 20);
	if (b == true)
	{
		printf("���۵� \n");
	}
	//printf("%d \n", value);
	printf("���α׷� ����\n");
}
