#include <stdio.h>
#include <stdlib.h>

// struct 서로 다른 타입을 묶은 집합

//struct bonnet
//{
//	int engine;
//	int pipe;
//	int piston;
//};

//struct car
//{
//	struct bonnet bn;	// 이중 구조체, 중첩 구조체
//	//int engine;
//	int wheel;
//	int body;
//};
//
//void carTest()
//{
//	struct car bm;		// 구조체 변수
//	bm.bn.engine = 300;	// . : 멤버 지정 연산자
//	scanf("%d", &bm.bn.engine);
//
//	struct car *p;					// 구조체 포인터 변수
//	p = &bm;			
//	scanf("%d", &p->bn.engine);		// (*p).body == p->body 간접 멤버지정 연산자
//}
//
//

struct _list
{
	int key;
	struct _list *next; // 자기 참조 구조체
};
typedef struct _list List;

// 좌우 기둥 만들기
List * head, *tail;


// 빨래 널기위한 초기화
void list_init()
{
	head = (List *)malloc(sizeof(List));	// 좌측 기둥
	tail = (List *)malloc(sizeof(List));	// 우측 기둥
	

	head->next = tail;						// 빨랫줄
	tail->next = tail;						// 우측 빨랫줄 매듭
}

void list_add(int data)
{
	List *nw = (List *)malloc(sizeof(List));	// 새 노드
	nw->key = data;

	nw->next = head->next;						// 좌측 기둥이 보고 있는 주소를 복사
	head->next = nw;							// 좌측 기둥이 새 노드를 가리킨다.

}

void list_view(void)
{
	List *wk;	// 빨래 걷는 친구
	wk = head->next; // 첫빨래의 주소
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
	printf("%d 는 존재하지 않습니다. \n",rdata);
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
			printf("%d는 %d번 위치에 존재합니다 \n", data, idx);
			return;
		}
		idx++;
		finder = finder->next;
	}
	printf("%d는 존재하지않습니다. \n", data);
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
			printf("%d는 %d번 위치에 존재합니다 \n", data, idx);
			printf("%d를 처음 위치에 존재하는 %d와 교체합니다. \n", data, head->next->key);

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
	printf("%d는 존재하지않습니다. \n", data);
}


int main(void)
{
	// 모든 자료구조는 반드시 초기화 함수가 존재해야한다
	list_init();

	// 첫번째 빨래 널기
	list_add(3);
	// 두번째 빨래 널기
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