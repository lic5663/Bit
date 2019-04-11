#include <stdio.h>
#include <stdlib.h>

// struct ���� �ٸ� Ÿ���� ���� ����

//struct bonnet
//{
//	int engine;
//	int pipe;
//	int piston;
//};

//struct car
//{
//	struct bonnet bn;	// ���� ����ü, ��ø ����ü
//	//int engine;
//	int wheel;
//	int body;
//};
//
//void carTest()
//{
//	struct car bm;		// ����ü ����
//	bm.bn.engine = 300;	// . : ��� ���� ������
//	scanf("%d", &bm.bn.engine);
//
//	struct car *p;					// ����ü ������ ����
//	p = &bm;			
//	scanf("%d", &p->bn.engine);		// (*p).body == p->body ���� ������� ������
//}
//
//

struct _list
{
	int key;
	struct _list *next; // �ڱ� ���� ����ü
};
typedef struct _list List;

// �¿� ��� �����
List * head, *tail;


// ���� �α����� �ʱ�ȭ
void list_init()
{
	head = (List *)malloc(sizeof(List));	// ���� ���
	tail = (List *)malloc(sizeof(List));	// ���� ���
	

	head->next = tail;						// ������
	tail->next = tail;						// ���� ������ �ŵ�
}

void list_add(int data)
{
	List *nw = (List *)malloc(sizeof(List));	// �� ���
	nw->key = data;

	nw->next = head->next;						// ���� ����� ���� �ִ� �ּҸ� ����
	head->next = nw;							// ���� ����� �� ��带 ����Ų��.

}

void list_view(void)
{
	List *wk;	// ���� �ȴ� ģ��
	wk = head->next; // ù������ �ּ�
	printf("\nhead ->");
	while (wk != tail)
	{
		printf(" %d ->", wk->key);
		wk = wk->next;
	}
	printf(" tail \n");
}

void list_delete(int rdata)
{
	List * kill;
	List * preNode;

	preNode = head;
	kill = head->next;

	while (kill != tail)
	{
		if (kill->key == rdata)
		{
			preNode->next = kill->next;
			free(kill);
			return;
		}
		preNode = preNode->next;
		kill = kill->next;
	}
	printf("%d �� �������� �ʽ��ϴ�. \n",rdata);
}

void list_find(int data)
{
	int idx = 0;
	List *finder;
	finder = head->next;
	while (finder != tail)
	{
		if (finder->key == data)
		{
			printf("%d�� %d�� ��ġ�� �����մϴ� \n", data, idx);
			return;
		}
		idx++;
		finder = finder->next;
	}
	printf("%d�� ���������ʽ��ϴ�. \n", data);
}

void MoveToFront(int data)
{
	int idx = 0;
	List * finder;
	List * preNode;
	//List * front;
	List * temp;

	preNode = head;
	finder = head->next;
	//front = head->next;

	while (finder != tail)
	{
		if (finder->key == data)
		{
			printf("%d�� %d�� ��ġ�� �����մϴ� \n", data, idx);
			printf("%d�� ó�� ��ġ�� �����ϴ� %d�� ��ü�մϴ�. \n", data, head->next->key);

			/*temp = front->next;
			front->next = finder->next;
			finder->next = temp;

			preNode->next = front;
			head->next = finder;*/

			temp = finder->next;
			finder->next = head->next->next;
			head->next->next = temp;

			preNode->next = head->next;
			head->next = finder;

			return;
		}
		idx++;
		preNode = preNode->next;
		finder = finder->next;
	}
	printf("%d�� ���������ʽ��ϴ�. \n", data);
}


int main(void)
{
	// ��� �ڷᱸ���� �ݵ�� �ʱ�ȭ �Լ��� �����ؾ��Ѵ�
	list_init();

	// ù��° ���� �α�
	list_add(3);
	// �ι�° ���� �α�
	list_add(2);
	list_add(7);
	list_add(9);
	list_add(8);
	list_add(14);

	list_view();

	list_delete(9);
	list_view();

	list_find(8);
	list_find(104);
	list_find(7);
	list_find(2);

	list_view();

	MoveToFront(7);

	list_view();

	return 0;
}