#include <stdio.h>
#include <stdlib.h>

typedef struct __num
{
	int fir;
	int sec;
}Num;

void func1(int n1, int n2)
{
	printf("%d + %d  \n", n1, n2);
}

void func2(Num * num)
{
	printf("%d + %d  \n", num->fir, num->sec );
}

void func3(Num * num)
{
	printf("%d + %d + %d + %d \n", num->fir , num->sec, (num+1)->fir, (num+1)->sec);
	//printf("%d + %d + %d + %d \n", (*num).fir, (*num).sec, num[1].fir, num[1].sec);
}

void main()
{
	Num a = { 1,2 }, b = { 3,4 }, c[2] = { 5,6,7,8 };

	func1(a.fir, a.sec);		// �Լ� ���ο��� 1+2 ���
	func2(&b);					// b�� �ּҸ� ������ 3+4 ���
	func3(&c);					// c�� �ּҸ� ������ 5+6+7+8 ���
}