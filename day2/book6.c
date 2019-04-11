#include <stdio.h>

void Pro1()
{
	int int_arr[10];
	int i;
	int max = 0;

	for (i = 0; i < 10; i++)
	{
		scanf_s("%d", int_arr + i);
		if (*(int_arr + i) > max)
			max = *(int_arr + i);
		getchar();
	}
	printf("입력된 수 : ");
	for (i = 0; i < 10; i++)
	{
		printf("%d ", *(int_arr + i));
	}
	printf("\n 최댓값 : %d ", max);
}

void Pro2()
{
	int i, sum = 0;

	for (i = 1; i <= 100; i++)
	{
		if (i % 2 == 0)
			sum += i;
	}
	printf("1~100 사이의 2의 배수 합은 : %d \n", sum);
}

void Pro3()
{
	for (int i = 1; i <= 100; i++)
	{
		int flag = 1;
		for (int j = 2; j < i; j++)
		{
			if (i%j == 0)
			{	
				flag = 0;
				break;
			}
		}
		if (flag)
			printf("%d ", i);
	}
}

void Pro4()
{
	int height = 9;
	int width = 7;
	//int height = 15;
	//int width = 13;
	for (int i = 1; i <= height; i++)
	{
		if (i < (height / 2 + 1))
		{
			for (int j = i; j < (width-1); j++)
			{
				printf("-");
			}
			for (int k = 0; k < i * 2 - 1; k++)
			{
				printf("*");
			}
		}
		else
		{
			for (int j = 0; j < (i - (width/2+1)) ; j++)
			{
				printf("-");
			}
			for (int k = 2*(height-i); k >=0 ; k--)
			{
				printf("*");
			}
		}
		
		printf("\n");
	}
}


void main()
{
	//Pro1();
	//Pro2();
	//Pro3();
	Pro4();
}