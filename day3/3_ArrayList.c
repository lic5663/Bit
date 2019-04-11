#include <stdio.h>
#include "ArrayList.h"

void ListInit(List * plist)
{
	
	plist->numOfData = 0;
	plist->curPosition = 0;
}

// 삽입
void LInsert(List * plist, LData data)
{
	if (plist->numOfData >= LIST_LEN)
	{
		puts("더 이상 저장 불가 \n");
		return;
	}
	plist->arr[plist->numOfData] = data;	// 현재 저장된 갯수 다음 배열에 데이터 저장
	(plist->numOfData)++;
}

int LFirst(List * plist, LData * pdata)
{
	if (plist->numOfData == 0)
		return FALSE;
	(plist->curPosition) = 0;
	*pdata = plist->arr[0];
	return TRUE;
}

int LNext(List * plist, LData * pdata)
{
	if (plist->curPosition >= ((plist->numOfData) - 1))
		return FALSE;

	(plist->curPosition)++;
	*pdata = plist->arr[plist->curPosition];
	return TRUE;
}

LData LRemove(List * plist)
{
	int rpos = plist->curPosition;	//삭제할 데이터의 인덱스 값 참조
	int num = plist->numOfData;
	int i;
	LData rdata = plist->arr[rpos];	//삭제할 데이터 임시로 저장

	// 삭제를 위한 데이터의 이동을 진행하는 반복문
	for (i = rpos; i < num - 1; i++)
		plist->arr[i] = plist->arr[i + 1];
	(plist->numOfData)--;
	(plist->curPosition)--;
	return rdata;
}

int LCount(List * plist)
{
	return plist->numOfData;
}


int main(void)
{
	return 0;
}