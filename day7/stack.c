#include <stdio.h>
#pragma warning (disable:4996)

// stack 후입선출
// 3가지 동작
//push()	삽입
//pop()		방출
//peek()	상단 데이터 보기
//
//1가지 속성
//stack 위치를 가리키는 top 포인터가 존재

#define STACK_SIZE 5
int STACK[STACK_SIZE];
int top;

void init_stack(void)
{
	top = -1;
}

void push(int data)
{
	if (top >= STACK_SIZE -1 )
	{
		printf("스택 수용량 초과 \n");
		return;
	}

	STACK[++top] = data;
}

int pop(void)
{
	if (top < 0)
	{
		printf("스택이 비어있습니다 \n");
		return -1;
	}
	
	return  STACK[top--];
}

void peek(void)
{
	if (top <0)
	{
		printf("스택이 비어있습니다 \n");
		return;
	}

	printf(" top : %d \n", STACK[top]);

}

void main()
{
	init_stack();
	push(8);
	push(5);
	push(7);
	push(9);
	push(4);

	push(10);
	push(10);
	push(10);
	push(10);

	printf("pop : %d \n", pop());
	printf("pop : %d \n", pop());
	printf("pop : %d \n", pop());
	printf("pop : %d \n", pop());
	printf("pop : %d \n", pop());

	printf("pop : %d \n", pop());
	printf("pop : %d \n", pop());
	printf("pop : %d \n", pop());

}
