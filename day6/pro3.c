#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning (disable:4996)

//문제 
//1. char *d[2][3]을 위한 포인터 pd를 선언하고
//pd를 위한 포인터를 선언하시오
//
//2. char **dd[2][3]을 위한 포인터
//pdd를 선언하고 pdd를 위한 포인터를 선언하시오.
//
//3. char a[7][3]과 b[2][3]를 가리키는 포인터 배열 pab를 사용하여
//pab의 0번째 포인터에 a의 주소
//pab의 1번째 포인터에 b의 주소를 가르키시오.


void Pro1()
{
	char *d[2][3];
	char *(*pd)[3] = d;
}

void Pro2()
{

}

void Pro3()
{
	char a[7][3];
	char b[2][3];

	char(*pab[2])[3];
	pab[0] = a;
	pab[1] = b;

}

int main(void)
{
	Pro1();
	Pro2();
	Pro3();
	

	return 0;
}