#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning (disable:4996)
#define TRUE	1
#define FALSE	0


// queue

#define QUEUE_SIZE 5
int queue[QUEUE_SIZE];
int front, rear;

void init_queue()
{
	front = rear = 0;
}

void put(int data)
{

	if ((rear + 1) % QUEUE_SIZE == front)
	{
		printf("overflow \n");
		return;
	}

	queue[rear++] = data;

	if (rear >= QUEUE_SIZE)
		rear = 0;
}

int get()
{
	int tmp;
	if (front == rear)
	{
		printf("남아있는 데이터가 없습니다 ");
		return -1;
	}

	tmp = front;
	front = ++front % 5;
	return queue[tmp];
}

void printQueue()
{
	int view = front;

	while (view != rear)
	{
		printf("%d ", queue[view]);
		view = ++view % QUEUE_SIZE;
	}
	printf("\n");
}

main()
{
	// 모든 자료구조는 초기화가 있어야한다.
	init_queue();
	put(3);
	put(1);
	put(2);
	put(4);
	put(5);
	
	printQueue();
	

	printf("get : %d \n", get());
	printf("get : %d \n", get());
	printf("get : %d \n", get());

	printQueue();

	put(2);
	put(4);
	put(5);

	printQueue();
}