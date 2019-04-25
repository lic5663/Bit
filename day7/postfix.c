#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning (disable:4996)
// stdarg.h는 C의 C 표준 라이브러리의 헤더로 인자 수를 제한 없이 할 수 있도록 하는 함수를 허용할 수 있도록 한다
//#include <stdarg.h>

typedef char *  va_list;
#define _INTSIZEOF(n)   ( (sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1) )
#define va_start(ap,v)  ( ap = (va_list)&v + _INTSIZEOF(v) )
#define va_arg(ap,t)    ( *(t *)((ap += _INTSIZEOF(t)) - _INTSIZEOF(t)) )
#define va_end(ap)      ( ap = (va_list)0 )

float average(int num, ...)
{
	va_list arg_ptr;
	int cnt, total = 0;

	va_start(arg_ptr, num);

	for (cnt = 0; cnt < num; cnt++)
		total += va_arg(arg_ptr, int);

	va_end(arg_ptr);

	return ((float)total / num);
}

main()
{
	float x;
	
	x = average(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
	printf("first avg is %f \n", x);
}