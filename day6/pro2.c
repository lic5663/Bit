#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

//���� �̸��� 2���� �迭�� �ְ� ���� ������ �̿��Ͽ� ���� �Ͻÿ�

//"����", "���ؿ�", "�պ���", "�����", "���α�", "����", "�����",
//"�ڼ���", "�ڼ���", "�ŵ���", "�̰��", "������", "Ȳ����", "������",
//"��ȣ��", "���϶�", "�̽¿�", "������", "������", "������"


void isort2(char(*a)[7], int n)
{
	int i, j;
	char t[7];
	for (i = 1; i < n; i++)
	{
		strcpy(t, a[i]);
		j = i;
		while (strcmp(a[j - 1], t) > 0 && j > 0)	
		{
			strcpy(a[j], a[j-1]);
			j--;
		}
		strcpy(a[j],t);
	}
}

void MySort(char * arr[], int numberOfHuman)
{
	int i, j;
	char * small;
	char * temp;


	for (i = 0; i < numberOfHuman; i++)
	{
		small = arr[i];
		for (j = i+1; j < numberOfHuman; j++)
		{
			if (strcmp(small, arr[j]) == -1)
			{
				temp = arr[j];
				arr[j] = *small;
				small = *temp;
				break;
			}
		}
	}
	
}

void printName(char ** name, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%s ", name[i]);
	}
	printf("\n");
	
}

int main(void)
{
	char * name[] = 
	{ "����","���ؿ�","�պ���","�����","���α�","����","�����",
	"�ڼ���","�ڼ���","�ŵ���","�̰��","������","Ȳ����","������",
	"��ȣ��","���϶�","�̽¿�","������","������","������", "������" };

	printName(name, 21);
	//MySort(name, 21);
	isort2(name, 21);
	printName(name, 21);


	return 0;
}