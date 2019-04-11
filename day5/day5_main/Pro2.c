#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

enum SUB
{
	KOR = 0,
	ENG,
	MATH,
	SUM,
	RANK
};

typedef struct __subject	// 국어 영어 수학 총점 랭킹
{
	int subName[5];
}Subject;

typedef struct __sung
{
	char name[10];
	float avg;
	Subject sub;
}Sung;


void initSung(int idx , Sung * sung)
{
	printf("%d번째 사람 이름 :", idx);
	gets(sung->name);

	printf("국어 점수 :");
	scanf("%d", &sung->sub.subName[KOR]);

	printf("영어 점수 :");
	scanf("%d", &sung->sub.subName[ENG]);

	printf("수학 점수 :");
	scanf("%d", &sung->sub.subName[MATH]);

	sung->sub.subName[SUM] = sung->sub.subName[KOR] + sung->sub.subName[ENG] + sung->sub.subName[MATH];
	sung->avg = sung->sub.subName[SUM] / (float)3;

	getchar();
}

void Rank(Sung *mans)
{
	int rank;
	for (int i = 0; i < 3; i++)
	{
		rank = 1;
		for (int j = 0; j < 3; j++)
		{
			if ((mans + i)->sub.subName[SUM] < (mans + j)->sub.subName[SUM])
				rank++;
		}
		(mans + i)->sub.subName[RANK] = rank;
	}
}

void printSung(Sung * man)
{
	for (int i = 0; i < 3; i++)
	{
		printf("\n이름: %s 국어: %3d 영어: %3d 수학: %3d ", (man+i)->name, (man + i)->sub.subName[KOR], (man + i)->sub.subName[ENG], (man + i)->sub.subName[MATH]);
		printf("총점: %3d 평균 %3.2f 랭킹 :%d \n", (man + i)->sub.subName[SUM], (man + i)->avg , (man + i)->sub.subName[RANK]);
	}
}

int main(void)
{
	Sung *man = (Sung*)malloc(sizeof(Sung)*3);

	for (int i = 0; i < 3; i++)
	{
		initSung(i + 1, man + i);
	}
	Rank(man);
	printSung(man);

	return 0;
}