#include <stdio.h>
#include <stdlib.h>
#define STACK_LEN 10
#define TRUE	1
#define FALSE	0


// 배열 기반 스택
typedef struct _arrayStack
{
	int stackArr[STACK_LEN];
	int topIndex;
}ArrayStack;

typedef ArrayStack Stack;

void StackInit(Stack * pstack)
{
	pstack->topIndex = -1;	// -1은 비어있다는걸 의미
}

int SIsEmpty(Stack * pstack)
{
	if (pstack->topIndex == -1)
		return TRUE;
	return FALSE;
}

void SView(Stack * pstack)
{
	printf("topIndex : %d , data : %d \n", pstack->topIndex,pstack->stackArr[pstack->topIndex]);
}

void SPush(Stack * pstack, int data)
{
	(pstack->topIndex)++;
	// 수용량 초과할 경우 오류 발생
	if (pstack->topIndex >= STACK_LEN)
	{
		printf("Stack Memory Error! \n");
		(pstack->topIndex)--;
		exit(-1);
	}

	pstack->stackArr[pstack->topIndex] = data;
	SView(pstack);
}

int SPop(Stack * pstack)
{
	int ridx;

	if (SIsEmpty(pstack))
	{
		printf("Stack Memory Error! \n");
		exit(-1);
	}

	ridx = pstack->topIndex;
	(pstack->topIndex)--;
	SView(pstack);
	return pstack->stackArr[ridx];
}
int SPeek(Stack * pstack)
{
	if (SIsEmpty(pstack))
	{
		printf("Stack Memory Error! \n");
		exit(-1);
	}

	return pstack->stackArr[pstack->topIndex];
}



int main(void)
{
	Stack * stack = (Stack*)malloc(sizeof(Stack));
	StackInit(stack);
	SPush(stack,10);
	SPush(stack, 11);
	SPush(stack, 12);
	SPush(stack, 15);
	SPush(stack, 17);
	SPush(stack, 19);
	SPush(stack, 20);

	SPop(stack);
	SPop(stack);
	SPop(stack);
	SPop(stack);
	SPop(stack);
	SPop(stack);

	

	return 0;
}