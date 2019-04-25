#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning (disable:4996)


//다음 각 메모리에 대한 포인터를 만들고
//
//대입시 warning이 발생하지 않도록 하시오
//
//예) char **a;
//
//char ***pa = &a;



 int main()
 {
	 char **a;
	 char *b[2];
	 char c[2][3];
	 char *d[2][3] = { "aa","bb","cc","dd","ee","ff" };
	 char (*e)[2][3];
	 char (*f[2])[3];

	 char ***pa = &a;
	 char **pb = b;
	 char (*pc)[3] = c;
	 char *(*pd)[3] = d;
	 char (**pe)[2][3] = &e;
	 char (**pf)[3] = f;



	 return 0;

 }

