#include <stdio.h>
#include <string.h>

void connect(int** pp, int* data_adress)
{
	*pp = data_adress;
}

void connectTest()
{
	int a;

	int *p;
	int **k;
	p = &a;
	k = &p;

	scanf_s("%d", &a);
	printf("%d\n", a);

	scanf_s("%d", p);
	printf("%d\n", *p);

	scanf_s("%d", *k);
	printf("%d\n", **k);

	printf("a = %d, *p = %d, **k = %d \n", a, *p, **k);

	a = 7;
	connect(&p,&a);
	printf("%d \n", *p); // 7�� ���
}

void swap1(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void swap2(int **ap, int **bp)
{
	int temp = **ap;
	**ap = **bp;
	**bp = temp;
}

void swap3(int ***app, int ***bpp)
{
	int temp = ***app;
	***app = ***bpp;
	***bpp = temp;
}

void swap4(int **ap, int **bp)
{
	int *temp = *ap;
	*ap = *bp;
	*bp = temp;
}

void swap5(int ***app, int ***bpp)
{
	int *temp = **app;
	**app = **bpp;
	**bpp = temp;
}

void swap6(int ***app, int ***bpp)
{
	int **temp = *app;
	*app = *bpp;
	*bpp = temp;
}

void swapTest()
{
	int a = 10;
	int b = 20;

	int *ap = &a;
	int *bp = &b;

	int **app = &ap;
	int **bpp = &bp;

	printf("a = %d, ap = %d, app = %d \nb = %d, bp = %d, bpp = %d \n", a, *ap, **app, b, *bp, **bpp);
	//swap1(&a, &b);
	//swap2(&ap, &bp);
	//swap3(&app,&bpp);
	//swap4(&ap, &bp);
	//swap5(&app, &bpp);
	swap6(&app, &bpp);
	printf("---swap----- \n");
	printf("a = %d, ap = %d, app = %d \nb = %d, bp = %d, bpp = %d \n", a, *ap, **app, b, *bp, **bpp);
}

void last(int *ka)
{
	*ka = 300;
}

void middle(int *pa)
{
	*pa = 200;
	last(pa);
}

void side()
{
	int a = 100;
	middle(&a);
	printf("%d", a);
}

void print(char **pp)
{
	// size_t : unsined int�� �ٸ� ��Ī�̴�.
	for (size_t i = 0; i < 3; i++)
	{
		printf("%s \n", *(pp+i));
	}
}

void arrayPointer()
{
	char *p[3] = { "abc" , "bbb" , "ccc" }; // �������� �迭
	print(p);
	
	char a[] = "abc";	// a:4byte
	//char b[3] = "abc";	// 3byte error
	char c[10];
	//c = "abc";			// error ���ڿ� "abc" 1. c�ڿ� �ι��ڰ� ���� 2. ���ڿ��� �ּҴ�. (c�� �̹� �ּҸ� �ǹ��ϹǷ� ���Ӱ� �ּҸ� �ټ� ����)
	strcpy_s(c,4 ,"abc");	// ������ �ذ���
	c[0] = 'z'; //zbc

	//char *pa = "abc";
	char *k;
	k = "abc";
	//puts(pa);
	puts(k);
	//strcpy(k, "abc");	// error
	k[0] = 'z'; // error.  string address ������ read only�̹Ƿ� ���� �Ұ�
	puts(k);
}

char *g = "abc";
void streamAddress()
{
	char *a = "abc";		// �б⸸ ������ �޸�
	char *b[3] = { "abc", "abc", "abc" };

	printf("%x %x %x \n", g, a, b[0]);

	//strcpy_s(a, 4, "xyz"); //error
	char buf[100];
	a = buf;				// �б� ���� ������ �޸�
	strcpy_s(a, 4, "xyz");
}

void get_num(int(*p)[4])
{
	int rx, cx;
	for (rx = 0; rx < 3; rx++)
	{
		for (cx = 0; cx < 4; cx++)
		{
			scanf_s("%d", &p[rx][cx]); // &(*(p+rx))[cx] , p[rx]+cx , *(px+rx)+cx
		}
	}
}

void put_num(int(*p)[4])
{
	int rx, cx;
	for (rx = 0; rx < 3; rx++)
	{
		for (cx = 0; cx < 4; cx++)
		{
			printf("%d ", p[rx][cx]); // (*(p+rx))[cx] , *(p[rx]+cx) , *(*(px+rx)+cx)
		}
	}
}

void arrPointer()
{
	int a[3][4];
	get_num(a);
	put_num(a);
}
// ���� ������
int main(void)
{
	//connectTest();
	//swapTest();
	//side();
	//arrayPointer();
	//streamAddress();
	//arrPointer();
	return 0;
}