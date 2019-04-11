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
	int *pa;		// int형 메모리의 주소를 담는 변수 pa
	pa = &a;		// a의 주소를 pa에 대입

	//scanf_s("%d", &a);
	//printf("%d \n", a);

	//// pa를 이용해서 scanf, printf
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

	//포인터 형에 관계없이 포인터형 변수는 4byte이다. 
	//(이유: 가상메모리가 4G인데 이는 2^32이다. 그리고 4byte또한 표현할 수 있는 최대 수는 2^32이므로 가상메모리 주소 전부를 표현 가능)
	char * pc;
	printf("%d \n", sizeof(pa));
	printf("%d \n", sizeof(pc));

	side();

}