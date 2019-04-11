#include <stdio.h>
#include <stdlib.h>
// ��ó�� �Լ�
#define swap(a,b) do {int t; t=a; a=b; b=t;}while(0)



int partition(int arr[], int s, int e)
{
	int big, small, pivot;
	big = s;
	small = e + 1;
	pivot = arr[big];
	while (big < small) 
	{

		//pivot���� ū���� ã�� ����. pivot���� ū ���� �������� �ε��� i ã��
		while (pivot >= arr[++big]);

		//pivot ���� �۰ų� ���� ���� ã�� ����. pivot���� ���� ���� �ε��� j ã��
		while (pivot < arr[--small]);

		if (big < small) {
			swap(arr[big], arr[small]);
		}
	}
	swap(arr[s], arr[small]);
	return small;
}

// �迭 , ������, ��������
void myqsort(int arr[], int s, int e)
{
	int mid;
	if (s < e) {
		mid = partition(arr, s, e);
		myqsort(arr, s, mid - 1);
		myqsort(arr, mid + 1, e);
	}
}

//����  �迭�� ���� �Ͻÿ�

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