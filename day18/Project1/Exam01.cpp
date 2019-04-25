#include <Windows.h>
#include <tchar.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("First"); //헝가리안 표기법. lp: long point, sz: string 끝이 zero(\0)인 클래스


// C언어 함수 호출 규약 : cdecl
// window API 함수 호출 규악 : stdcall
// WINAPI: 호출방식을 의미한다.
// 함수마다 자신의 스택인 스택프레임을 가진다. 함수 호출이란 스택프레임에 인자값을 넘겨주는 것이다.
// cdecl은 인자 값을 우측부터 순차적으로 스택에 넣어준다. ex) ADD(a,b,c) 하면 c b a 순으로 스택에 쌓임
// 호출자는 caller 호출당한건 callee. caller가 callee의 스택에 인자를 쌓아준다. 어떻게 쌓고 어떻게 없앨것이냐를 정한것이 호출 규약이다.
// cdecl은 callee에 쌓인 인자를 caller가 제거해준다. c에선 가변인자 함수가 존재해서 callee쪽에서는 인자가 몇개인지 모른다. caller만 인자 개수를 안다.
// 그래서 인자값을 알고있는 caller가 시간좀 걸리고 복잡하지만 callee의 스택프레임에 존재하는 인자를 제거한다.
// stdcall 방식은 스택에 쌓는 순서는 동일하지만 가변인자 방식을 사용하지 않으므로 callee가 스택을 제거한다. 
// WINAPI라는 호출 규약을 넣어 stdcall임을 명시한다. 안적으면 cdecl방식으로 처리한다.
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR IpszCmdParam, int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASSEX WndClass;		// 윈도우 구조는 구조체로 정의되어있다. 필요한 정보를 담을 것이다.
	g_hInst = hInstance;

	WndClass.cbClsExtra = 0;	// 안씀 꺼져
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// 백그라운드용 브러시 핸들. 배경으로 뭔색을 넣을것이냐.
																	// GetStockObject 기존에 존재하는 요소를 들고오는 경우 사용하는 함수
																	// HBRUSH로 casting한다.
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = WndProc;					// lp:포인터 fn:함수 -> 함수포인터. 관례적으로 WndProc를 쓴다. 
	WndClass.lpszClassName = lpszClass;
	WndClass.lpszMenuName = NULL;					// 메뉴 안만듬
	WndClass.style = CS_HREDRAW | CS_VREDRAW;		// 사이즈 변경시 redaw해라. 
	WndClass.hIconSm = 0;							// 스몰아이콘은 안쓴다.
	WndClass.cbSize = sizeof(WNDCLASSEX);			// 사이즈 비교로 wndclass인지 wndclassex인지 알려고 크기 정보를 준다.
	RegisterClassEx(&WndClass);						// wndclassex써서 여기도 ex쓴다.
	// 윈도 등록 (윈도우 클래스명, 타이틀바 표시명, 윈도우 스타일, 윈도우 위치, 크기 , 부모윈도우 핸들, 윈도우에서 사용할 메뉴핸들, 윈도우 생성 주체, 특수목적)
	// ATOM CreateWindow(laszClassName, laszWindowName, dwStyle, x, y ,nWidth, nHeight, hwndParent, hmenu, hInst, lpvParam)
	// ATOM : 유일한 존재임을 보장하는 형태를 리턴.
	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, (HMENU)NULL, hInstance, NULL);
	// 등록된 윈도우 제작
	ShowWindow(hWnd, nCmdShow);


	// 윈도우는 메세지 드리블 형태. 외부에서 메세지가 오면 그에 따라 행동. 
	// System Queue에 모든 이벤트가 다 들어온다. (키보드, 마우스 등) 각 어플리케이션마다 쓰레드가 존재하는데 쓰레드는 쓰레드 큐를 가진다.
	// system queue에서 Thread Queue로 메시지를 넘긴다.
	while (GetMessage(&Message, NULL, 0, 0))	// 외부 이벤트를 계속 받아준다.
	{
		//GetMessage는 WM_QUIT를 만나는 순간 0값을 반환. 
		TranslateMessage(&Message);
		DispatchMessage(&Message);	// 꺼내온 메세지를 인자로 넘긴다. 아래의 iMessage인자로 넘겨준다.
	}
	return (int)Message.wParam;	
}

// 호출 규약 CALLBACK. stdcall임. 내부에서 호출당해서 쓴거.
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	// win32에서 하는건 메세지에 따른 수많은 case를 작성해서 이벤트를 처리하는 과정이다.
	switch (iMessage)
	{
	case WM_DESTROY:
		PostQuitMessage(0);	// 종료 메세지를 보낸다. 특별한 사항이 없으면 이 부분은 반드시 넣어준다.
		return 0;
	}
	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}

// Boiler Plate : 보일러 명패. 상투적 내용으로 빼면 법에 걸림
// 윗 부분은 그런 개념이라고 보면된다. p22