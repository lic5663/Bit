#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning (disable:4996)
#define TRUE	1
#define FALSE	0

int SeqSearch(int A[], int key, int n)
{
	// 다운 카운팅
	// 컴파일러가 연산할때 업카운팅보다 다운카운팅이 한줄 적다.
	int k = n;
	A[0] = key;
	while (A[k] != key)
	{
		k--;
	}

	return k;
}


int bSearch(char * arr[], int first, int end, char * key)
{

	while (first <= end)
	{
		int mid = (first + end) / 2;

		int tmp = strcmp(key, arr[mid]);

		switch (tmp)
		{
		case -1: end = mid - 1; break;
		case 0: return mid;
		case 1: first = mid + 1; break;
		default:
			break;
		}
	}
	return -1;
}



int binarySearch(char * arr[], int first, int end, char * key)
{
	if (first > end)
		return -1;

	int mid = (first + end) / 2;

	int tmp = strcmp(key, arr[mid]);

	switch (tmp)
	{
	case -1: binarySearch(arr, first, mid-1, key); break;
	case 0: return mid;
	case 1: binarySearch(arr, mid + 1, end, key); break;
	default: 
		break;
	}

}

int cmp(const void *p, const void * k)
{
	char *pp = (char*)p;
	char *pk = (char*)k;

	int tmp = strcmp((char*)p, (char*)k);
	return tmp;
}

int compare(char **arg1, char **arg2)
{
	/* Compare all of both strings: */
	return strcmp(*arg1, *arg2);
}

int main(void)
{
	char * key[] = { "Alice", "Bill", "Carol", "David", "Elvis", "Fred", "Gabriel",
		"Helen", "Isabel", "Jane", "Kuper", "Louic", "Mathilda", "Nadia", "Olive",
		"Pablo", "Queen", "Rambo", "Scarlet", "Trisha", "Umberto", "Vincent",
		"Wily", "Xxx", "Yuki", "Zorro" };




	int idx = binarySearch(key, 0, sizeof(key)/sizeof(char*), "Pablo");
	if (idx != -1)
		printf("대상 인덱스 %d \n %s \n", idx, key[idx]);
	else
		printf("그런건 없어요 \n");


	int idx2 = bSearch(key, 0, sizeof(key) / sizeof(char*), "Pablo");
	if (idx2 != -1)
		printf("대상 인덱스 %d \n %s \n", idx2, key[idx2]);
	else
		printf("그런건 없어요 \n");

	char **result;
	result = (char**)bsearch("pablo", key, sizeof(key) / sizeof(key[0]), sizeof(char*), (int(*)(const void*, const void*))compare);

	if (result == NULL)
		printf("그런건 없어요 \n");
	else
	{
		printf("대상 인덱스 %d \n", (int)result - (int)key[0]);
	}

}