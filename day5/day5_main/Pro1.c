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

	func1(a.fir, a.sec);		// 함수 내부에서 1+2 출력
	func2(&b);					// b의 주소를 던져서 3+4 출력
	func3(&c);					// c의 주소를 던져서 5+6+7+8 출력
}