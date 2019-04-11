#include <stdio.h>
#pragma warning (disable:4996)

// stack ���Լ���
// 3���� ����
//push()	����
//pop()		����
//peek()	��� ������ ����
//
//1���� �Ӽ�
//stack ��ġ�� ����Ű�� top �����Ͱ� ����

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
		printf("���� ���뷮 �ʰ� \n");
		return;
	}

	STACK[++top] = data;
}

int pop(void)
{
	if (top < 0)
	{
		printf("������ ����ֽ��ϴ� \n");
		return -1;
	}
	
	return  STACK[top--];
}

void peek(void)
{
	if (top <0)
	{
		printf("������ ����ֽ��ϴ� \n");
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
