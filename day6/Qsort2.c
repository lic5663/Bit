#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning (disable:4996)

typedef int(*FCMP)(void *, void *);

int cmp_i(const void *p, const void*k)
{
	return *(int*)p - *(int*)k;
}

int cmp_s(const void *p, const void*k)
{
	return strcmp((char*)p, (char*)k);
}


void *func(void *base, size_t num, size_t width, FCMP fcmp)
{


	//내부적으로 cmp_i나 cmp_s를 호출한다 //결과는 -1(음수), 0, 1(양수)을 리턴한다.

	//printf("%d\n", fcmp());
	printf("%d \n", fcmp((char*)base+width, base));


}
main()
{
	int a[5] = { 10000000,3,1,5,2 };
	char b[10][10] = { "aaaa","aaaa" };

	func(a, 5, sizeof(int), cmp_i);
	func(b, 2, sizeof(b[0]), cmp_s);
}


