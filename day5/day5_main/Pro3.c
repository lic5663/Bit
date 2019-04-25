#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#pragma warning(disable:4996)
#define TRUE	1
#define FALSE	0


// 1~10���� �����͸� �������� �Է¹޾� ����Ʈ�� ����
// �ߺ��� ��� �缱��
// ���Խ� ������������ ����
// �����͸� �� ������ �ű�� �Լ�
// �ٷ� �� ���� �ٲٴ� �Լ� �߰�


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
	printf("\n ���� : %d\n", data);
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
	printf("\n��� : ");
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
	printf("�����Ͱ� �������� �ʽ��ϴ�. \n");
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
	printf("�����Ͱ� �������� �ʽ��ϴ�. \n");
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
	printf("\n�ϼ��Ǿ����ϴ�.\n");

	while (TRUE)
	{
		printf("\n�� �������� �Űܾ��ϴ� ������ �Է��Ͻÿ�  :");
		scanf("%d", &input);
		MoveToFront(list, input);
		ListView(list);


		printf("\n�ճ��� �ٲ�� �ϴ� ������ �Է��Ͻÿ�  :");
		scanf("%d", &input);
		TranPose(list, input);
		ListView(list);
	}

	return 0;
}