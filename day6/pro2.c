#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

//다음 이름을 2차원 배열에 넣고 다음 정렬을 이용하여 정렬 하시오

//"배상우", "소준영", "손병국", "고승희", "구민교", "김기백", "김다희",
//"박선애", "박성경", "신동열", "이경수", "조희은", "황상진", "강상헌",
//"이호세", "전하람", "이승연", "정낙현", "조민희", "이인찬"


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
	{ "배상우","소준영","손병국","고승희","구민교","김기백","김다희",
	"박선애","박성경","신동열","이경수","조희은","황상진","강상헌",
	"이호세","전하람","이승연","정낙현","조민희","이인찬", "지도현" };

	printName(name, 21);
	//MySort(name, 21);
	isort2(name, 21);
	printName(name, 21);


	return 0;
}