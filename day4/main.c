#include <stdio.h>
#include <string.h>

// ������ �迭�� 1���� ó�� �ޱ�
void array_1to2(char *p)
{
	puts(p);
}

// ������ �迭�� ������ ó�� �ޱ�
void array_2to2(char p[1000][10])
{
	puts(p[2]);
}

// ���� �迭 �׽�Ʈ
void arrayTest()
{
	char a[3][10] = { "abc","dfg","zzzzzzzz" };
	array_1to2(a[2]);
	array_2to2(a);
}

void print_a(char **p)	// char *p[] // char *p[10]
{
	// 0��°�� abc���� bc�� ����ϴ� printf��
	printf("%s \n", &(*p)[1]);					// *p+1 //p[0] +1	
	// 1��°�� home���� h�� ����ϴ� printf��
	printf("%c \n", p[1][0]);					// *(p[1]) // *(*(p+1)) // (*(p+1))[0]
	// 2��°�� print���� i�� ����ϴ� printf��
	printf("%c \n", p[2][2]);					// *(p[2]+2) // *(*(p+1)+2) // (*(p+1))[2]
}

void printTest()
{
	char *a[3] = { "abc","home","printf" };
	print_a(a);
}

// �Լ��� �ּҴϱ� �Լ��� ����Ű�� �����͵� �������̴�.
int add(int a, int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

int mul(int a, int b)
{
	return a * b;
}

int div(int a, int b)
{
	return a / b;
}


int main(void)
{
	// �Լ������� �迭
	int(*p[4])(int, int) = {add,sub,mul,div };
	//1 35 4       2		�д� ����

	for (size_t i = 0; i < 4; i++)
		printf("%d\n", p[i](10, 5));

	//int rlt;
	//rlt = add(10, 5);
	//printf("%d\n", rlt);


	//int (*p)(int, int);	//int(*p)[3]
	//p = add;
	//rlt = p(10, 5);
	//printf("%d\n", rlt);

	//p = sub;
	//rlt = p(10, 5);
	//printf("%d\n", rlt);

	//p = mul;
	//rlt = p(10, 5);
	//printf("%d\n", rlt);

	//p = div;
	//rlt = p(10, 5);
	//printf("%d\n", rlt);


	

	return 0;
}


//int main(int argc, char *argv[])
//{
//	//arrayTest();
//	//printTest();
//	
//	int first = atoi(argv[1]);
//	int sec = atoi(argv[3]);
//
//	switch (argv[2][0])
//	{
//	case '+': printf("%d + %d = %d\n", first, sec, first + sec);
//	default:
//		break;
//	}
//
//	return 0;
//}