#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning (disable:4996)

//���� 
//1. char *d[2][3]�� ���� ������ pd�� �����ϰ�
//pd�� ���� �����͸� �����Ͻÿ�
//
//2. char **dd[2][3]�� ���� ������
//pdd�� �����ϰ� pdd�� ���� �����͸� �����Ͻÿ�.
//
//3. char a[7][3]�� b[2][3]�� ����Ű�� ������ �迭 pab�� ����Ͽ�
//pab�� 0��° �����Ϳ� a�� �ּ�
//pab�� 1��° �����Ϳ� b�� �ּҸ� ����Ű�ÿ�.


void Pro1()
{
	char *d[2][3];
	char *(*pd)[3] = d;
}

void Pro2()
{

}

void Pro3()
{
	char a[7][3];
	char b[2][3];

	char(*pab[2])[3];
	pab[0] = a;
	pab[1] = b;

}

int main(void)
{
	Pro1();
	Pro2();
	Pro3();
	

	return 0;
}