#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 100
#pragma warning(disable:4996)


// �ڽ��� �ּҸ� �Է¹޾Ƽ� ���´� �ּ��� ũ�⸸ŭ�� ���� �Ҵ��ϰ� ���� �� ����Ͻÿ�
void dynamicMemory()
{
	char buffer[MAX_LEN];
	printf("�ּҸ� �Է��Ͻÿ�\n");
	gets_s(buffer, MAX_LEN);
	
	char * ch = (char*)malloc(strlen(buffer)+1);	//�ι��� ��� ���� �ʿ� +1
	strcpy_s(ch, strlen(buffer)+1 ,buffer);

	puts(ch);
	free(ch);										// �ι��� ��� ���ҽ� ���� �����ɸ�
}

int main(void)
{
	int *p;
	p = malloc(4);		// 4����Ʈ �޸𸮸� �� ������ ��� �ּҸ� ����

	//int a;			// ���� ���� ���� ��) stack ������ �Ѵ� ����
	//int *p;
	//p = &a; 
	//printf("%d", *p);

	int a[5];
	int *q = a;

	int *r;
	r = (int*)malloc(5 * sizeof(int));

	dynamicMemory();
	
	return 0;
}