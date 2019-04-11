#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

void printInt(int *arr, int size);
void printDbl(double *arr, int size);
void printstr(char(*arr)[7], int size);

int comp_i(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

//라이브러리 제공하는 qsort를 위한 comp_d 함수 완성
int comp_d(const void* a, const void* b) 
{
	if (*(double*)a > *(double*)b)
		return 1;
	else if (*(double*)a < *(double*)b)
		return -1;
	else
		return 0;

}

//라이브러리 제공하는 qsort를 위한 comp_s 함수 완성
int comp_s(const void* a, const void* b) {
	return strcmp((char*)a, (char*)b);
}




int main(void) {
	int arri[] = { 3,4,1,5,2,8,9,6,10,7 };
	double arrd[] = { 3.2, 5.6, 4.3, 8.7, 2.3, 4.5, 2.1, 2.3, 4.6, 4.5 };
	char name[][7] = { "배상우", "소준영", "손병국", "고승희", "구민교",
		"김기백", "김다희", "박선애", "박성경", "신동열",
		"이경수", "조희은", "황상진", "강상헌", "이호세",
		"전하람", "이승연", "정낙현", "조민희", "이인찬",
		"지도현" };
	qsort(arri, sizeof(arri) / sizeof(arri[0]), sizeof(int), comp_i);
	//qsort(소팅 대상 ,소팅 개수, 1개 개수의 크기, 정렬기준)
	printInt(arri, sizeof(arri) / sizeof(arri[0]));

	qsort(arrd, sizeof(arrd) / sizeof(arrd[0]), sizeof(double), comp_d);
	printDbl(arrd, sizeof(arrd) / sizeof(arrd[0]));

	//라이브러리 qsort를 이용하여 2차원배열에 있는 문자열을 정렬합시다.

	qsort(name, sizeof(name) / sizeof(name[0]), sizeof(name[0]), comp_s);
	printstr(name, sizeof(name) / sizeof(name[0]));

	return 0;
}
void printInt(int *arr, int size) {
	int dx = 0;
	for (dx = 0; dx < size; ++dx) {
		printf("%d ", arr[dx]);
	}
	printf("\n");
}

void printDbl(double *arr, int size) {
	int dx = 0;
	for (dx = 0; dx < size; ++dx) {
		printf("%.1f  ", arr[dx]);
	}
	printf("\n");
}

void printstr(char (*arr)[7], int size) {
	int dx = 0;
	for (dx = 0; dx < size; ++dx) {
		printf("%s ", arr[dx]);
	}
	printf("\n");
}