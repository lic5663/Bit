#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning (disable:4996)
#define TRUE	1
#define FALSE	0

// void (*signal(int signum, void(*handler)(int)))(int);
//  1	 3  5				4						2

//1. void
//2. (int)
//3. *	// 저런 함수를 가리키는 포인터
//4. (int sn, void(*h)(int)) // 포인터를 리턴하는 삼수
//5. signal

// code hiding
typedef void v;		// void와 같은 v
typedef v fv(int);	// void를 리턴하는 함수 fv -> 함수타입 fv
typedef fv * pfv;	// fv타입을 가리키는 포인터 pfv
typedef pfv fpfv();	// 아래 시그널 형태의 함수

fpfv signal;

pfv signal()
{
	return func;
}

// 위 아래는 동일 표현

//void(*signal())(int) 		// char * signal // int * signal
//{
//	return func;
//}

void func(int a)
{
	puts("func");
}


typedef int i;
typedef i fi();
typedef fi * pfi;
typedef pfi pffi();
typedef pffi * ppffi;

typedef char * pc;
typedef pc  arrpc[10];
typedef arrpc * parrpc;
typedef parrpc fparrpc();
typedef fparrpc * pfparrpc;



main()
{
	(signal())(10);
}

