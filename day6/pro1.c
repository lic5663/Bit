#include <stdio.h>
#include <stdlib.h>
// 전처리 함수
#define swap(a,b) do {int t; t=a; a=b; b=t;}while(0)



int partition(int arr[], int s, int e)
{
	int big, small, pivot;
	big = s;
	small = e + 1;
	pivot = arr[big];
	while (big < small) 
	{

		//pivot보다 큰값을 찾는 구문. pivot보다 큰 값을 가진수의 인덱스 i 찾기
		while (pivot >= arr[++big]);

		//pivot 보다 작거나 같은 값을 찾는 구문. pivot보다 작은 값의 인덱스 j 찾기
		while (pivot < arr[--small]);

		if (big < small) {
			swap(arr[big], arr[small]);
		}
	}
	swap(arr[s], arr[small]);
	return small;
}

// 배열 , 시작점, 종료지점
void myqsort(int arr[], int s, int e)
{
	int mid;
	if (s < e) {
		mid = partition(arr, s, e);
		myqsort(arr, s, mid - 1);
		myqsort(arr, mid + 1, e);
	}
}

//다음  배열을 정렬 하시오

main()
{
	int arri[] = { 3,4,1,5,2,8,9,6,10,7 };
	for (size_t i = 0; i < 10; i++)
	{
		printf("%d ", arri[i]);
	}
	printf("\n");

	myqsort(arri, 0, 9);
	for (size_t i = 0; i < 10; i++)
	{
		printf("%d ", arri[i]);
	}
}