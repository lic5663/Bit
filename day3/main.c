#include <stdio.h>
#include <string.h>

// ������ ����

void change(int* a)
{
	*a = 100;
}

void swap(int* pa, int* pb)
{
	int temp = *pa;
	*pa = *pb;
	*pb = temp;
}

void check(int *p, int len)
{
	//p�� �̿��� a�� ��� ���� ���
	for (int i = 0; i < len; i++)
		printf("%d ", i[p]); // i[p] == p[i]
	printf("\n");
}

// ���ĸŰ����� *p�� ����Ͽ� ���ĺ� k�� ������ ������ ����ϴ� �Լ�
void put_a(char* p)
{
	/*while (1)
	{
		if (*p == '\0')
			break;
		printf("%c", *p);
		p = p + 1;
	}
	printf("\n");*/

	while (*p)
		putchar(*p++);
	putchar('\n');
}

void mystrcpy(char* source, char* destination)
{
	/*while (*source != '\0')
		*destination++ = *source++;
	*destination++ = '\0';*/

	while (*destination++ = *source++);
}

void mystrcat(char* dst, char* add)
{
	while (*++dst);
	while (*dst++ = *add++);


}

int main(void)
{
	int a = 7;
	int* p;
	p = &a;
	

	//int a = 7;
	//change(a);
	//printf("%d \n", a); //7�� ���

	//change(&a);
	change(p);

	printf("%d \n", a);

	int b = 10, c = 5;
	printf("%d %d \n", b, c);
	swap(&b, &c);
	printf("%d %d \n", b, c);

	int arr[5] = {3,4,1,5,2};
	int *q;
	q = arr;	// a==&a[0] �迭���� ���ο���� �ּ�
	int len = sizeof(arr) / sizeof(int);
	printf("%d \n", len);
	check(q, len);

	char ch[] = "abcdefghijklmnopqrstuvwxzy";
	puts(ch);
	put_a(ch);

	char dst[100];
	char src[] = "abcde";

	//strcpy_s(dst, src,);
	mystrcpy(src, dst);
	puts(dst);

	mystrcat(dst, "zzz");
	puts(dst);

	return 0;
}