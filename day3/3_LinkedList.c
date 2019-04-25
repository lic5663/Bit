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

// ����Ʈ ������ ����
void LInsert(list * plist, LData data)
{
	node * newnode = CreateNode(data);
	
	// ���� ������ ����
	if (plist->head == NULL)
	{
		plist->head = newnode;
		plist->tail = newnode;
		plist->NumOfData++;
	}
	// ù��° ���� ������ ����
	else
	{
		plist->tail->next = newnode;		// �� ��带 tail ���� ����
		plist->tail = plist->tail->next;	// tail�� ����Ű�� ���� ���ο� ���� ����
		plist->NumOfData++;					// ������ ���� ���� ����
	}
}

// ����Ʈ ������ Ž��
// ���� Ž��
int LFirst(list * plist, LData * pdata)
{
	if (plist->head == NULL)					// list�� ����� �����Ͱ� ������ Ž���� �����Ͱ� �����Ƿ� �ٷ� false ��ȯ
		return FALSE;

	plist->cur = plist->head;					// ���� �����̹Ƿ� cur�� �ʱ�ȭ �����ش�.

	*pdata = plist->cur->LData;
	return TRUE;

}
// �ļ� Ž��
int LNext(list * plist, LData * pdata)
{
	plist->cur = plist->cur->next;
	if (plist->cur == NULL)
		return FALSE;

	*pdata = plist->cur->LData;
	//plist->cur = plist->cur->next;
	return TRUE;
}


// Ž�� ����
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





// ����Ʈ ������ ����
void LRemove(list * plist)
{

}

// ADT : �ʱ�ȭ, ����, ����, Ž��

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