#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning (disable:4996)
#define TRUE	1
#define FALSE	0

// 우선순위큐 priority Q (heap)// tree로 하고 배열로 구성해야 속도가 나온다


typedef struct _tree
{
	int key;
	struct _tree *left;
	struct _tree *right;
}Tree;

Tree * head, *tail;

void preoder(Tree *p)
{
	if (p != NULL)
	{
		printf("%d ", p->key);
		preoder(p->left);
		preoder(p->right);
	}
}

void inorder(Tree *p)	// tree 정렬, bst 이진 탐색트리
{
	if (p != NULL)
	{
		inorder(p->left);
		printf("%d ", p->key);
		inorder(p->right);
	}
}

void postorder(Tree *p)
{
	if (p != NULL)
	{
		postorder(p->left);
		postorder(p->right);
		printf("%d ", p->key);
		
	}
}

int get_depth(Tree *p, int dep)
{
	int L_dep, R_dep;
	L_dep = R_dep = dep;

	if (p->left != NULL)
		L_dep = get_depth(p->left, dep + 1);
	if (p->right != NULL)
		R_dep = get_depth(p->right, dep + 1);

	if (L_dep >= R_dep)
		return L_dep;
	return R_dep;
}

//스택을 사용한 전위순회
// 1. 루트를 push
// 2. stack이 비어있지 않다면 pop해서 key를 출력
// 3. pop 대상의 오른쪽 왼쪽 자식순으로 push후 2번으로 가서 반복

//스택을 사용한 중위순회
//1. 루트를 push
//2. 왼쪽 자식이 있으면 계속 push
//3. 더이상 넣을 왼쪽자식이 없으면 stack에서 pop한다,
//4. pop한 대상의 오른쪽 자식을 1번.으로 삼고 반복한다.

// 큐를 이용한 층별순회
//1. 루트를 queue에 put()
//2. queue가 비어있지 않으면 뺀다 get()
//3. 뺀 노드의 왼쪽 오른쪽 자식을 put
//4. 2번 반복

main()
{
	// 구조체 변수
	Tree a1 = { 1,NULL,NULL },
		b2 = { 2,NULL,NULL },
		c3 = { 3,NULL,NULL },
		d4 = { 4,NULL,NULL },
		e5 = { 5,NULL,NULL },
		f6 = { 6,NULL,NULL },
		g7 = { 7,NULL,NULL },
		h8 = { 8,NULL,NULL },
		i9 = { 9,NULL,NULL };

	a1.left = &b2;
	a1.right = &e5;

	b2.right = &c3;
	c3.left = &d4;

	e5.left = &f6;
	f6.left = &g7;
	f6.right = &h8;
	h8.left = &i9;

	preoder(&a1); // 전위순회 : 루트타고 왼쪽 오른쪽
	puts("");
	inorder(&a1); // 중위순회 : 루트타고 왼쪽루트 오른쪽
	puts("");
	postorder(&a1); // 후위순회: 왼쪽 오른쪽 루트
	puts("");
	puts("");

	printf("%d \n",get_depth(&a1, 0));
	printf("%d \n", get_depth(a1.left, 0));
	printf("%d \n", get_depth(a1.right, 0));


}