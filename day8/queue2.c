#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning (disable:4996)
#define TRUE	1
#define FALSE	0
#define MAX_LEN 10
#define NUM	10


typedef struct _queue
{
	int front[NUM], rear[NUM];
	int queue [NUM][MAX_LEN];
}Queue;

// 큐 초기화
void initQueue(Queue * pque)
{


	for (int i = 0; i < NUM; i++)
	{
		pque->front[i] = 0;
		pque->rear[i] = 0;
	}
}

// 큐 데이터 삽입
void put(Queue *pque, int data, int choice)
{
	int tmp;
	
	switch (choice)
	{
	case 0: tmp = data % 10; break;
	case 1: tmp = data / 10; break;
	default: break;
	}

	(pque->queue)[tmp][pque->rear[tmp]] = data;
	(pque->rear[tmp])++;

	if (pque->rear[tmp] >= MAX_LEN)
		pque->rear[tmp] = 0;

}

// 큐 데이터 꺼내기
int get(Queue *pque, int idx)
{
	int tmp;

	// 큐가 비어있을 경우
	if (pque->front[idx] == pque->rear[idx])
	{
		return 0;
	}

	tmp = pque->queue[idx][pque->front[idx]];
	(pque->front[idx])++;

	if (pque->front[idx] >= MAX_LEN)
		pque->front[idx] = 0;
	
	return tmp;
}

void printQueue(Queue * pqueue)
{

	int view;
	for (int i = 1; i < NUM; i++)
	{
		printf("%d : ", i);
		view = pqueue->front[i];

		while (view != pqueue->rear[i])
		{
			printf("%d ", pqueue->queue[i][view]);
			view = ++view % MAX_LEN;
		}	
		printf("\n");
	}
}


int main(void)
{
	Queue n1, n10;
	int tmp;

	initQueue(&n1);
	initQueue(&n10);

	int arr[] = { 72,81,64,31,29,43,77,26,15,48,25,95 };

	for (int i = 0; i< sizeof(arr)/sizeof(char) ; i++)
		put(&n1, arr[i], 0);

	printQueue(&n1);
	printf("\n\n");

	for (int i = 1; i < 10; i++)
	{
		while (tmp = get(&n1, i))
		{
			put(&n10, tmp, 1);
		}
	}
		
	printQueue(&n10);

	for (int i = 1; i < 10; i++)
	{
		while (tmp = get(&n10, i))
		{
			printf("%d ",tmp);
		}
	}
	puts("");
	
	
}
