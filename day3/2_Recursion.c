#include <stdio.h>

int Bsearch(int arr[], int len, int target)
{
	int first = 0;
	int last = len - 1;
	int mid;

	while (first <= last)
	{
		mid = (first + last) / 2;

		if (target == arr[mid])
			return mid;
		else
		{
			if (target < arr[mid])
				last = mid - 1;
			else
				first = mid + 1;
		}
	}
	return -1;
}

void BsearchTest()
{
	int arr[] = { 1,3,5,7,9,10,11,13 };
	int idx;

	idx = Bsearch(arr, sizeof(arr) / sizeof(int), 7);

	if (idx == -1)
		printf("탐색 실패 \n");
	else
		printf("타겟 저장 인덱스 : %d \n", idx);

}

int BSearchRecur(int ar[], int first, int last, int target)
{
	int mid;
	if (first > last)
		return -1;
	
	mid = (first + last) / 2;

	if (ar[mid] == target)
		return mid;
	else if (ar[mid] > target)
		BSearchRecur(ar, first, mid - 1, target);
	else
		BSearchRecur(ar, mid + 1, last, target);
}

void BSearchRecurTest()
{
	int idx;
	int arr[] = { 1,3,5,7,9 };

	idx = BSearchRecur(arr, 0, sizeof(arr) / sizeof(int), 5);
	if (idx == -1)
		printf("탐색 실패 \n");
	else
		printf("타겟 인덱스 : %d \n", idx);
}

void HanoiTowerMove(int num, char from, char by, char to)
{
	if (num == 1)
		printf("원반 1을 %c에서 %c로 이동 \n", from, to);
	else
	{
		HanoiTowerMove(num - 1, from, to, by);
		printf("원반 %d을(를) %c에서 %c로 이동 \n", num, from, to);
		HanoiTowerMove(num - 1, by, from, to);
	}
}

void HanoiTest()
{
	HanoiTowerMove(7, 'A', 'B', 'C');
}

int main(void)
{
	BsearchTest();
	BSearchRecurTest();
	HanoiTest();
	

}