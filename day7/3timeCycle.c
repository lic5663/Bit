#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning (disable:4996)

typedef int ElementType;

typedef struct tagNode
{
	ElementType Data;
	struct tagNode* PrevNode;
	struct tagNode* NextNode;
} Node;
Node* CreateNode(ElementType NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = NewData;
	NewNode->PrevNode = NULL;
	NewNode->NextNode = NULL;

	return NewNode;
}


/*  노드 추가 */
void AppendNode(Node** Head, Node* NewNode)
{

	if ((*Head) == NULL)
	{
		*Head = NewNode;
		(*Head)->NextNode = *Head;
		(*Head)->PrevNode = *Head;
	}
	else
	{

		Node* Tail = (*Head)->PrevNode;

		Tail->NextNode->PrevNode = NewNode;
		Tail->NextNode = NewNode;

		NewNode->NextNode = (*Head);
		NewNode->PrevNode = Tail;

	}
}
int main(void)
{
	int   i = 0;
	int   Count = 0;
	Node* List = NULL;
	Node* NewNode = NULL;
	Node* Current = NULL;

	/*  노드 5개 추가 */
	for (i = 0; i < 5; i++) //이 반복문이 3번 도는 경우까지의 메모리 모양 그리기
	{
		NewNode = CreateNode(i);
		AppendNode(&List, NewNode);
	}
}