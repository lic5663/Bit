#include <stdio.h>

void cold(void) { puts("cold");}	// 클라이언트
void hot(void) { puts("hot"); }		// 클라이언트

void aircon(void(*p)(void)) // 서버코드, 서버
{
	p();	// call back
}

main()						// 클라이언트 코드, 클라이언트
{
	aircon(cold);			// call

	aircon(hot);
}