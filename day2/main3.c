#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void side()
{

	printf("---------side---------- \n");
	int dx;
	int rnum;
	srand(time(NULL));
	// random table
	for (dx = 0; dx < 5; dx++)
	{
		rnum = rand()%100+1;
		printf("%d \n", rnum);
	}
}

void main()
{
	int a = 10;
	int *pa;		// int�� �޸��� �ּҸ� ��� ���� pa
	pa = &a;		// a�� �ּҸ� pa�� ����

	//scanf_s("%d", &a);
	//printf("%d \n", a);

	//// pa�� �̿��ؼ� scanf, printf
	//scanf_s("%d", pa);
	//printf("%d \n", *pa);

	int *pb;
	int b = 5;
	pb = &b;

	printf("pa = %d ", *pa);
	printf("pb = %d ", *pb);
	printf("\n");

	int temp;
	temp = *pa;
	*pa = *pb;
	*pb = temp;

	printf("pa = %d ", *pa);
	printf("pb = %d ", *pb);
	printf("\n");

	//������ ���� ������� �������� ������ 4byte�̴�. 
	//(����: ����޸𸮰� 4G�ε� �̴� 2^32�̴�. �׸��� 4byte���� ǥ���� �� �ִ� �ִ� ���� 2^32�̹Ƿ� ����޸� �ּ� ���θ� ǥ�� ����)
	char * pc;
	printf("%d \n", sizeof(pa));
	printf("%d \n", sizeof(pc));

	side();

}