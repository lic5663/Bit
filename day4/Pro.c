#include <stdio.h>

typedef unsigned int uint;
typedef int(*myfp_t)(int, int); // �Լ������� ��Ī�� �Լ� ��Ī�� ��ü�Ѵ�.

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
//int temp(int a,int b,int(*p_func)(int,int)) { return p_func(a,b); }	// �Լ� ������ Ȱ��
int temp(int a, int b, myfp_t p) { return p(a, b); }				// �Լ� ������ Ȱ�� (�� �Ʒ� ����)

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

	void *p;	//���� ������ ��� ���� �ּҸ� �������ִ�.
	char ch = 'A';
	p = &ch;
	printf("%c\n", *(char *)p);

	int i = 123;
	p = &i;
	printf("%d\n", *(int *)p);

	char arr[] = "abcde";
	p = arr;
	printf("%s\n", (char*)p);		//abcde���

	for (int i = 0; i < 3; i++)
		printf("%c ", *((char*)p+i));
	printf("\n");

	printf("%c\n", *((char*)p)++ ); // p++���·� ��� 'a'
	printf("%c\n", *(char*)p); // 'b'

	

	return 0;
}