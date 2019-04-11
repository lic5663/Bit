#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#pragma warning(disable:4996)
#define TRUE	1
#define FALSE	0


// 1~10까지 데이터를 랜덤으로 입력받아 리스트에 삽입
// 중복일 경우 재선정
// 삽입시 오름차순으로 정렬
// 데이터를 맨 앞으로 옮기는 함수
// 바로 앞 노드와 바꾸는 함수 추가


typedef struct __node
{
	int key;
	struct __node * next;
}Node;

typedef struct __list
{
	Node * head;
	Node * tail;
	int numberOfData;
}List;

void InitList(List * plist)
{
	plist->head = (Node*)malloc(sizeof(Node));
	plist->tail = (Node*)malloc(sizeof(Node));
	
	plist->head->next = plist->tail;
	plist->tail->next = plist->tail;

	plist->numberOfData = 0;
}

void LInsert(List * plist, int data)
{
	Node * newnode = (Node*)malloc(sizeof(Node));
	newnode->key = data;
	

	if (plist->numberOfData == 0)
	{
		plist->head->next = newnode;
		newnode->next = plist->tail;
		(plist->numberOfData)++;
		return;
	}
	else
	{
		Node * prenode = plist->head;
		Node * cur = plist->head->next;
		
		while (cur != plist->tail)
		{
			if (cur->key > data)
			{
				prenode->next = newnode;
				newnode->next = cur;
				(plist->numberOfData)++;
				return;
			}
			cur = cur->next;
			prenode = prenode->next;
		}
		prenode->next = newnode;
		newnode->next = plist->tail;
		(plist->numberOfData)++;
		return;

	}
}

int IsDuplicated(List * plist, int data)
{
	Node * search = plist->head->next;
	system("cls");
	printf("\n 랜덤 : %d\n", data);
	while (search != plist->tail)
	{
		if (search->key == data)
			return TRUE;
		search = search->next;
	}
	return FALSE;
}

void InsertRandom(List * plist)
{
	int randomNumber;
	srand(time(NULL));

	randomNumber = rand() % 10 + 1;

	while (IsDuplicated(plist, randomNumber))
	{
		randomNumber = rand() % 10 + 1;
	}

	LInsert(plist, randomNumber);
}


void ListView(List * plist)
{
	Node * viewer = plist->head->next;
	printf("\n출력 : ");
	while (viewer != plist->tail)
	{
		printf("%d ", viewer->key);
		viewer = viewer->next;
	}
		
}

void MoveToFront(List * plist, int data)
{
	Node * preNode = plist->head;
	Node * target = plist->head->next;

	while (target != plist->tail)
	{
		if (target->key == data)
		{
			preNode->next = target->next;
			target->next = plist->head->next;
			plist->head->next = target;
			return;
		}
		target = target->next;
		preNode = preNode->next;
	}
	printf("데이터가 존재하지 않습니다. \n");
	return;
}

void TranPose(List * plist, int data)
{
	Node * prepreNode = plist->head;
	Node * preNode = plist->head;
	Node * target = plist->head->next;
	int IsSecond = 0;

	while (target != plist->tail)
	{
		if (target->key == data)
		{
			prepreNode->next = target;
			preNode->next = target->next;
			target->next = preNode;
			return;
		}
		target = target->next;
		preNode = preNode->next;
		if (IsSecond)
			prepreNode = prepreNode->next;
		IsSecond = 1;
	}
	printf("데이터가 존재하지 않습니다. \n");
	return;
}



int main(void)
{
	int input;
	List * list = (List*)malloc(sizeof(List));
	InitList(list);

	while (list->numberOfData < 10 )
	{
		InsertRandom(list);
		ListView(list);
		_sleep(1000);
	}
	printf("\n완성되었습니다.\n");

	while (TRUE)
	{
		printf("\n맨 앞쪽으로 옮겨야하는 정보를 입력하시오  :");
		scanf("%d", &input);
		MoveToFront(list, input);
		ListView(list);


		printf("\n앞노드와 바꿔야 하는 정보를 입력하시오  :");
		scanf("%d", &input);
		TranPose(list, input);
		ListView(list);
	}

	return 0;
}