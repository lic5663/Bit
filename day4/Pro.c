#include <stdio.h>

typedef unsigned int uint;
typedef int(*myfp_t)(int, int); // 함수포인터 명칭이 함수 명칭을 대체한다.

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
//int temp(int a,int b,int(*p_func)(int,int)) { return p_func(a,b); }	// 함수 포인터 활용
int temp(int a, int b, myfp_t p) { return p(a, b); }				// 함수 포인터 활용 (위 아래 같음)

char * f(void)
{
	return "abcdef";
}

int main(void)
{
	int a = 10, b = 5;

	printf("%d\n", temp(a,b,add));

	for (size_t i = 0; i < 3; i++)
	{
		printf("%c", f()[i]);
	}

	void *p;	//범용 포인터 모든 형태 주소를 담을수있다.
	char ch = 'A';
	p = &ch;
	printf("%c\n", *(char *)p);

	int i = 123;
	p = &i;
	printf("%d\n", *(int *)p);

	char arr[] = "abcde";
	p = arr;
	printf("%s\n", (char*)p);		//abcde찍기

	for (int i = 0; i < 3; i++)
		printf("%c ", *((char*)p+i));
	printf("\n");

	printf("%c\n", *((char*)p)++ ); // p++형태로 찍기 'a'
	printf("%c\n", *(char*)p); // 'b'

	

	return 0;
}