#include <stdio.h>

void cold(void) { puts("cold");}	// Ŭ���̾�Ʈ
void hot(void) { puts("hot"); }		// Ŭ���̾�Ʈ

void aircon(void(*p)(void)) // �����ڵ�, ����
{
	p();	// call back
}

main()						// Ŭ���̾�Ʈ �ڵ�, Ŭ���̾�Ʈ
{
	aircon(cold);			// call

	aircon(hot);
}