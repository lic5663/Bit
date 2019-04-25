#include <stdio.h>
#include <stdlib.h>
#define TRUE	1
#define FALSE	0

typedef int LData;

typedef struct __NODE
{
	int LData;
	struct __NODE *next;
}node;

typedef struct __LINKED_LIST
{
	node * head;
	node * tail;
	node * cur;
	int NumOfData;
}list;

void Linit(list * plist)
{
	plist->head = NULL;
	plist->tail = NULL;
	plist->cur = NULL;
	plist->NumOfData = 0;
}

node * CreateNode(LData data)
{
	node * newnode = (node*)malloc(sizeof(node));
	newnode->next = NULL;
	newnode->LData = data;
	return newnode;
}

// 리스트 데이터 삽입
void LInsert(list * plist, LData data)
{
	node * newnode = CreateNode(data);
	
	// 최초 데이터 삽입
	if (plist->head == NULL)
	{
		plist->head = newnode;
		plist->tail = newnode;
		plist->NumOfData++;
	}
	// 첫번째 이후 데이터 삽입
	else
	{
		plist->tail->next = newnode;		// 새 노드를 tail 끝에 부착
		plist->tail = plist->tail->next;	// tail을 가리키는 곳을 새로운 노드로 이전
		plist->NumOfData++;					// 데이터 저장 갯수 증가
	}
}

// 리스트 데이터 탐색
// 최초 탐색
int LFirst(list * plist, LData * pdata)
{
	if (plist->head == NULL)					// list에 저장된 데이터가 없을때 탐색할 데이터가 없으므로 바로 false 반환
		return FALSE;

	plist->cur = plist->head;					// 최초 접근이므로 cur을 초기화 시켜준다.

	*pdata = plist->cur->LData;
	return TRUE;

}
// 후속 탐색
int LNext(list * plist, LData * pdata)
{
	plist->cur = plist->cur->next;
	if (plist->cur == NULL)
		return FALSE;

	*pdata = plist->cur->LData;
	//plist->cur = plist->cur->next;
	return TRUE;
}


// 탐색 통합
void LExplore(list * plist)
{
	int data;

	if (LFirst(plist, &data))
	{
		printf("%d ", data);
		while (LNext(plist, &data))
		{
			printf("%d ", data);
		}
	}
	printf("\n\n");
}





// 리스트 데이터 삭제
void LRemove(list * plist)
{

}

// ADT : 초기화, 삽입, 삭제, 탐색

int main(void)
{
	list List;
	Linit(&List);
	LInsert(&List, 17);
	LInsert(&List, 18);
	LInsert(&List, 19);
	LInsert(&List, 20);
	LInsert(&List, 30);

	LExplore(&List);

	return 0;
}