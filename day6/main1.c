#include <stdio.h>
#include <stdlib.h>

typedef struct _list
{
	int key;
	struct _list * next;
}List;

List * head;
List * tail;

void list_init()
{
	head = (List*)malloc(sizeof(List));
	tail = (List*)malloc(sizeof(List));
	head->next = tail;
	tail->next = tail;
}

void list_add_sort(int data)
{
	List *nw;
	List *prv;	// 앞쪽을 가리키는 포인터
	List *cmp;
	prv = head;
	cmp = head->next;

	while (cmp != tail && cmp->key <= data)	// 작거나 같으면 더 큰값을 찾아야한다
	{
		prv = prv->next;
		cmp = cmp->next;
	}

	nw = (List*)malloc(sizeof(List));
	nw->key = data;

	prv->next = nw;
	nw->next = cmp;

}

void list_delete_all()
{
	List * cmp_list = head->next;
	List * del_list;

	while (cmp_list != tail)
	{
		del_list = cmp_list;
		cmp_list = cmp_list->next;
		free(del_list);
	}
	head->next = tail;
}

void list_view()
{
	List * view = head->next;
	printf("\nhead ");
	while (view != tail)
	{
		printf("%d ", view->key);
		view = view->next;
	}
	printf("tail\n");
}

int main(void)
{
	list_init();

	list_add_sort(5);
	list_add_sort(7);
	list_add_sort(1);
	list_add_sort(3);

	list_view();

	list_delete_all();

	list_view();

	
	return 0;
}