#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning (disable:4996)
#define TRUE	1
#define FALSE	0

// 인터넷 접속기록을 스택에 쌓고 뒤로가기 앞으로 가기 구현

// 현재 접속 웹페이지 :
//1. URP 접속
//2. 방문 기록 보기
//3. 뒤로
//4. 앞으로
//0. 종료

// 뒤로 갔다가 앞으로 가면 삭제

typedef struct _Node
{
	struct _Node *next;
	char * url;
}Node;

typedef struct _Stack
{
	Node * top;
	Node * cur;		// 다용도 현재 포인터
	int numOfData;	// 현재 스택 수용량
}Stack;

// 스택 초기화
void InitStack(Stack * pstack)
{
	pstack->top = (Node*)malloc(sizeof(Node));	// 더미 노드 생성
	pstack->top->next = NULL;
	pstack->cur = pstack->top->next;
	pstack->numOfData = 0;
}

// pop
char* pop(Stack * pstack)
{
	if (pstack->top->next == NULL)
	{
		printf("이전 데이터 없음\n");
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
	printf("URL을 입력해주세요 : ");
	gets(buffer);
	push(pstack, buffer);
}

void viewStack(Stack * pstack)
{
	Node * viewer = pstack->top->next;
	int i;

	printf("앞으로 이동 할 수 있는 목록\n");
	printf("========================================\n");
	i = 0;
	while (viewer != pstack->cur)
	{
		printf("%d. %s\n", i+1, viewer->url);
		viewer = viewer->next;
		i++;
	}

	viewer = viewer->next;

	printf("뒤로 이동 할 수 있는 목록\n");
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
		printf("현재 접속중인 웹 페이지: %s\n", pstack->cur->url);
	printf("========================================\n");
	printf("1. URL 접속\n");
	printf("2. 방문 기록 보기\n");
	printf("3. 뒤로\n");
	printf("4. 앞으로\n");
	printf("0. 종료\n");
	printf("========================================\n");
	printf("선택 : ");

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