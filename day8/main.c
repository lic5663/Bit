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
//3. *	// ���� �Լ��� ����Ű�� ������
//4. (int sn, void(*h)(int)) // �����͸� �����ϴ� ���
//5. signal

// code hiding
typedef void v;		// void�� ���� v
typedef v fv(int);	// void�� �����ϴ� �Լ� fv -> �Լ�Ÿ�� fv
typedef fv * pfv;	// fvŸ���� ����Ű�� ������ pfv
typedef pfv fpfv();	// �Ʒ� �ñ׳� ������ �Լ�

fpfv signal;

pfv signal()
{
	return func;
}

// �� �Ʒ��� ���� ǥ��

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

