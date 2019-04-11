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
	node * current_node;	// ���� ���� ���
	int capacity;			// ��� ����
}list;

// list �ʱ�ȭ
void initializeList(list * plist)
{
	node * newnode = (node*)malloc(sizeof(node));
	newnode->next = NULL;
	newnode->data = 0;

	plist->head = newnode;
	plist->current_node = plist->head;
	plist->capacity = 0;

}

// ����
void insert(list *plist, int insert_data)
{
	// ���ο� ��� ����
	node * newnode = (node*)malloc(sizeof(node));
	newnode->next = NULL;
	newnode->data = insert_data;

	// ���� ��ġ Ž��
	plist->current_node = plist->head;
	//�������� ����
	while (plist->current_node->next != NULL && newnode->data > plist->current_node->next->data)
	{
		plist->current_node = plist->current_node->next;
	}

	// ���� ��ġ�� ���ο� ��带 �����Ѵ�.
	newnode->next = plist->current_node->next;
	plist->current_node->next = newnode;
	
	// �������� �߰�
	plist->capacity++;

}

// ����
void removeList(list *plist, int remove_data)
{
	// �ش� ������ Ž��
	node * search_node = plist->head->next;
	plist->current_node = plist->head;
	while (search_node->next != NULL)
	{
		if (search_node->data == remove_data)
		{
			plist->current_node->next = search_node->next;			// �����Ǳ� ���� ��忡 �����Ǵ� ��� next ����
			printf("pop : %d \n", search_node->data);				// �����Ǵ� ��� ������ ���
			free(search_node);
			(plist->capacity)--;
			break;
		}
		plist->current_node = plist->current_node->next;
		search_node = search_node->next;
	}

}

// ���
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

// Ž��
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