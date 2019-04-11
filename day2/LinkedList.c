#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
	struct Node * next;
	int data;
}node;

typedef struct LinkedList
{
	node * head;
	node * current_node;	// 현재 참조 노드
	int capacity;			// 노드 개수
}list;

// list 초기화
void initializeList(list * plist)
{
	node * newnode = (node*)malloc(sizeof(node));
	newnode->next = NULL;
	newnode->data = 0;

	plist->head = newnode;
	plist->current_node = plist->head;
	plist->capacity = 0;

}

// 삽입
void insert(list *plist, int insert_data)
{
	// 새로운 노드 생성
	node * newnode = (node*)malloc(sizeof(node));
	newnode->next = NULL;
	newnode->data = insert_data;

	// 삽입 위치 탐색
	plist->current_node = plist->head;
	//오름차순 정렬
	while (plist->current_node->next != NULL && newnode->data > plist->current_node->next->data)
	{
		plist->current_node = plist->current_node->next;
	}

	// 삽입 위치에 새로운 노드를 삽입한다.
	newnode->next = plist->current_node->next;
	plist->current_node->next = newnode;
	
	// 보유갯수 추가
	plist->capacity++;

}

// 삭제
void removeList(list *plist, int remove_data)
{
	// 해당 데이터 탐색
	node * search_node = plist->head->next;
	plist->current_node = plist->head;
	while (search_node->next != NULL)
	{
		if (search_node->data == remove_data)
		{
			plist->current_node->next = search_node->next;			// 삭제되기 이전 노드에 삭제되는 노드 next 연결
			printf("pop : %d \n", search_node->data);				// 삭제되는 노드 데이터 출력
			free(search_node);
			(plist->capacity)--;
			break;
		}
		plist->current_node = plist->current_node->next;
		search_node = search_node->next;
	}

}

// 출력
void printList(list * plist)
{
	plist->current_node = plist->head->next;
	for (int i = 0; i < plist->capacity; i++)
	{
		printf("%d ", plist->current_node->data);
		plist->current_node = plist->current_node->next;
	}
	printf("\n");
}

// 탐색
int searchList(list * plist, int search_data)
{
	int index = 0;
	plist->current_node = plist->head->next;
	for (int i = 0; i < plist->capacity; i++)
	{
		if (plist->current_node->data == search_data)
		{
			return index;
		}
		plist->current_node = plist->current_node->next;
	}
}



int main(void)
{
	list mylist;
	initializeList(&mylist);
	insert(&mylist, 7);
	insert(&mylist, 8);
	insert(&mylist, 15);
	insert(&mylist, 32);
	insert(&mylist, 17);
	insert(&mylist, 51);
	insert(&mylist, 11);
	insert(&mylist, 13);

	printList(&mylist);

	removeList(&mylist, 32);
	printList(&mylist);

	removeList(&mylist, 15);
	printList(&mylist);

	removeList(&mylist, 11);
	printList(&mylist);

	removeList(&mylist, 51);
	printList(&mylist);

	removeList(&mylist, 91);
	printList(&mylist);


	return 0;
}