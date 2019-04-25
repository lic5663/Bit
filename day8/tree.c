#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning (disable:4996)
#define TRUE	1
#define FALSE	0

// �켱����ť priority Q (heap)// tree�� �ϰ� �迭�� �����ؾ� �ӵ��� ���´�


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

void inorder(Tree *p)	// tree ����, bst ���� Ž��Ʈ��
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

//������ ����� ������ȸ
// 1. ��Ʈ�� push
// 2. stack�� ������� �ʴٸ� pop�ؼ� key�� ���
// 3. pop ����� ������ ���� �ڽļ����� push�� 2������ ���� �ݺ�

//������ ����� ������ȸ
//1. ��Ʈ�� push
//2. ���� �ڽ��� ������ ��� push
//3. ���̻� ���� �����ڽ��� ������ stack���� pop�Ѵ�,
//4. pop�� ����� ������ �ڽ��� 1��.���� ��� �ݺ��Ѵ�.

// ť�� �̿��� ������ȸ
//1. ��Ʈ�� queue�� put()
//2. queue�� ������� ������ ���� get()
//3. �� ����� ���� ������ �ڽ��� put
//4. 2�� �ݺ�

main()
{
	// ����ü ����
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

	preoder(&a1); // ������ȸ : ��ƮŸ�� ���� ������
	puts("");
	inorder(&a1); // ������ȸ : ��ƮŸ�� ���ʷ�Ʈ ������
	puts("");
	postorder(&a1); // ������ȸ: ���� ������ ��Ʈ
	puts("");
	puts("");

	printf("%d \n",get_depth(&a1, 0));
	printf("%d \n", get_depth(a1.left, 0));
	printf("%d \n", get_depth(a1.right, 0));


}