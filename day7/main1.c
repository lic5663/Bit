#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning (disable:4996)

typedef struct _D_node Dnode;

typedef struct _D_node
{
	int data;
	Dnode * pre;
	Dnode * next;
}Dnode;

typedef struct _List
{
	Dnode * head;
	Dnode * tail;

	int numOfData;
};

int main(void)
{

}