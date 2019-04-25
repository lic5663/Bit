#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning (disable:4996)
#define TRUE	1
#define FALSE	0

// ���ͳ� ���ӱ���� ���ÿ� �װ� �ڷΰ��� ������ ���� ����

// ���� ���� �������� :
//1. URP ����
//2. �湮 ��� ����
//3. �ڷ�
//4. ������
//0. ����

// �ڷ� ���ٰ� ������ ���� ����

typedef struct _Node
{
	struct _Node *next;
	char * url;
}Node;

typedef struct _Stack
{
	Node * top;
	Node * cur;		// �ٿ뵵 ���� ������
	int numOfData;	// ���� ���� ���뷮
}Stack;

// ���� �ʱ�ȭ
void InitStack(Stack * pstack)
{
	pstack->top = (Node*)malloc(sizeof(Node));	// ���� ��� ����
	pstack->top->next = NULL;
	pstack->cur = pstack->top->next;
	pstack->numOfData = 0;
}

// pop
char* pop(Stack * pstack)
{
	if (pstack->top->next == NULL)
	{
		printf("���� ������ ����\n");
		return "X";
	}

	Node * popnode = pstack->top->next;
	pstack->top->next = pstack->top->next->next;

	char * str = (char*)malloc(sizeof(strlen(popnode->url) + 1));
	strcpy(str, popnode->url);
	free(popnode);
	(pstack->numOfData)--;

	return str;
}

// push
void push(Stack * pstack, char * urlData)
{
	Node * newnode = (Node*)malloc(sizeof(Node));
	newnode->url = (char*)malloc(sizeof(strlen(urlData) + 1));
	strcpy(newnode->url, urlData);

	Node * del = pstack->top->next;
	while (del != pstack->cur)
	{
		del = del->next;
		pop(pstack);
	}

	newnode->next = pstack->top->next;
	pstack->top->next = newnode;

	pstack->cur = pstack->top->next;
	(pstack->numOfData)++;
}



void inputURL(Stack * pstack)
{
	char buffer[100];
	printf("URL�� �Է����ּ��� : ");
	gets(buffer);
	push(pstack, buffer);
}

void viewStack(Stack * pstack)
{
	Node * viewer = pstack->top->next;
	int i;

	printf("������ �̵� �� �� �ִ� ���\n");
	printf("========================================\n");
	i = 0;
	while (viewer != pstack->cur)
	{
		printf("%d. %s\n", i+1, viewer->url);
		viewer = viewer->next;
		i++;
	}

	viewer = viewer->next;

	printf("�ڷ� �̵� �� �� �ִ� ���\n");
	printf("========================================\n");
	i = 0;
	while (viewer != NULL)
	{
		printf("%d. %s\n", i+1, viewer->url);
		viewer = viewer->next;
		i++;
	}
}

void MoveBack(Stack * pstack)
{
	pstack->cur = pstack->cur->next;
}

void MoveForward(Stack * pstack)
{
	Node * pre = pstack->top;

	while (pre->next != pstack->cur)
	{
		pre = pre->next;
	}

	pstack->cur = pre;
}


void PrintMenu(Stack * pstack, int * choice)
{
	if (pstack->top->next != NULL)
		printf("���� �������� �� ������: %s\n", pstack->cur->url);
	printf("========================================\n");
	printf("1. URL ����\n");
	printf("2. �湮 ��� ����\n");
	printf("3. �ڷ�\n");
	printf("4. ������\n");
	printf("0. ����\n");
	printf("========================================\n");
	printf("���� : ");

	scanf("%d", choice);
	getchar();
}

enum MENU
{
	EXIT,
	URL,
	VIEW,
	BACK,
	FORWARD
};

int main(void)
{
	Stack stack;
	int choice;
	int repeatFlag = TRUE;
	InitStack(&stack);

	while (repeatFlag)
	{
		PrintMenu(&stack, &choice);

		switch (choice)
		{
		case EXIT: repeatFlag = FALSE; break;
		case URL: inputURL(&stack); break;
		case VIEW: viewStack(&stack); break;
		case BACK: MoveBack(&stack); break;
		case FORWARD: MoveForward(&stack); break;
		default:
			break;
		}
	}


	return 0;
}