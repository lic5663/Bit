#include <stdio.h>
#include <stdlib.h>
#define TRUE	1
#define FALSE	0

typedef struct _node
{
	int data;
	struct _node *next;
}Node;

typedef struct _listStack
{
	Node * head;
}ListStack;

typedef ListStack Stack;

void StackInit(Stack * pstack)
{
	pstack->head = NULL;
}


int SIsEmpty(Stack * pstack)
{
	if (pstack->head == NULL)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack * pstack, int data)
{
	Node * newnode = (Node*)malloc(sizeof(Node));
	newnode->data = data;
	newnode->next = pstack->head;
	pstack->head = newnode;
}

int SPop(Stack * pstack)
{
	Node * rnode;
	int rdata;

	if (SIsEmpty(pstack))
	{
		printf("STACK IS EMPTY!");
		return -1;
	}
	rnode = pstack->head;
	rdata = pstack->head->data;

	pstack->head = pstack->head->next;
	free(rnode);

	return rdata;
}

int SPeek(Stack * pstack)
{
	if (SIsEmpty(pstack))
	{
		printf("STACK IS EMPTY!");
		exit(-1);
	}
	return pstack->head->data;
}

int main(void)
{
	Stack stack;
	StackInit(&stack);

	SPush(&stack, 1);
	SPush(&stack, 2);
	SPush(&stack, 3);
	SPush(&stack, 4);
	SPush(&stack, 5);

	while (!SIsEmpty(&stack))
	{
		printf("%d ", SPop(&stack));
	}

	return 0;
}