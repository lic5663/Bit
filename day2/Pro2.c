#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define width 4
#define height 5

void Pro1()
{
	int a[100];
	//------------------------------------
	for (int i = 0; i < 100; i++)
	{
		a[i] = i;
		printf("%d ", a[i]);
	}
	printf("\n\n");
	//------------------------------------
	for (int i=1; i<=100 ; i++)
	{
		a[i-1] = i;
		printf("%d ", a[i-1]);
	}
	printf("\n\n");
	//------------------------------------
	int i = 0;
	int idx = 0;
	while (idx < 100)
	{
		if (i % 2 == 0)
		{
			a[idx] = i;
			idx++;
		}
		i++;
	}
	for (int i = 0; i < 100; i++)
		printf("%d ", a[i]);
	printf("\n\n");
	//------------------------------------
	for (int i = 1; i <= 100; i++)
	{
		a[i-1] = i;
		if (i % 3 == 0)
			printf("%d ", a[i-1]);
		else if (i % 7 == 0)
			printf("%d ", a[i - 1]);
	}
	printf("\n\n");
	//------------------------------------
	for (int i = 0; i < 100; i++)
	{
		if (i % 2 == 0)
			a[i] = 99 - i;
		else
			a[i] = i - 1;
		printf("%d ", a[i]);
	}
	printf("\n\n");
	//------------------------------------
	for (int i = 1; i <= 100; i++)
		a[i-1] = i;
	i = 0;
	while (a[i] < 54)
	{
		printf("%d ", a[i]);
		i++;
	}
	printf("\n\n");
	//------------------------------------
	int n1, n2;
	scanf_s("%d %d", &n1, &n2);
	if (n1 > n2)
	{
		for (int i = n2; i <= n1; i++)
			printf("%d ", i);
	}
	else
	{
		for (int i = n1; i <= n2; i++)
			printf("%d ", i);
	}
	printf("\n\n");
	//------------------------------------
	getchar();
}

void Pro2()
{
	int a[5] = { 3,4,1,5,2 };
	// a 배열 안의 가장 큰 값을 찾아 출력하는 프로그램
	int max = 0;
	for (int i = 0; i < 5; i++)
	{
		if (max < a[i])
			max = a[i];
	}
	printf("가장 큰 수 : %d \n", max);
}

void Pro3()
{
	int a[height][width] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	int horizontal_sum = 0;
	int vertical_sum[width] = { 0 };
	// 배열 a의 값을 행과 열의 합으로 구하여 다음과 같이 출력
	// 1 2 3 | 6
	// 4 5 6 | 15
	// -------
	// 5 7 9

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			printf("%3d ", a[i][j]);
			horizontal_sum += a[i][j];
			vertical_sum[j] += a[i][j];
		}
		printf(" | %d \n" , horizontal_sum);
		horizontal_sum = 0;
	}
	for (int i = 0; i < width; i++)
		printf("-----");
	printf("\n");
	for (int i = 0; i < width; i++)
	{
		printf("%3d ", vertical_sum[i]);
	}
	printf("\n");
}

void Pro4()
{
	int age, count =1;
	int answer;
	int pre_answer = 0;
	int flag = 0;
	int first = 1;
	srand(time(NULL));
	age = rand() % 100 + 1;
	

	printf("%d \n", age);
	while (1)
	{
		printf("나이를 입력하세요 : ");
		scanf_s("%d", &answer);

		if (first)
			pre_answer = answer;

		if (answer == age)
		{
			printf("정답입니다. %d번 만에 맞추셨습니다 \n", count);
			break;
		}

		if (answer < age)
		{
			if (flag == -1 && pre_answer > answer)
				printf("왜 이전값보다 적은 값을 적으셨습니까.\n");
			else
			{
				printf("그보단 나이가 많습니다 \n");
				pre_answer = answer;
				flag = -1;
			}
		}
		if (answer > age)
		{
			if (flag == 1 && pre_answer < answer)
				printf("왜 이전값보다 큰 값을 적으셨습니까.\n");
			else
			{
				printf("그보단 나이가 적습니다 \n");
				pre_answer = answer;
				flag = 1;
			}	
		}
		count++;
		
		first = 0;
	}

}

void Pro5()
{
	int intArr[45];
	for (int i = 0; i < 45; i++)
		intArr[i] = i + 1;

	srand(time(NULL));
	int rnum;
	int MaxIndex = 45;

	while (1)
	{
		for (int i = 0; i < MaxIndex; i++)
			printf("%d ", intArr[i]);
		printf("\n");

		if (MaxIndex > 1)
			rnum = rand() % (MaxIndex)+1;
		else if (MaxIndex == 1)
			rnum = 0;
		printf("%d \n", intArr[rnum]);

		intArr[rnum] = intArr[MaxIndex-1];
		MaxIndex--;


		if (MaxIndex == 0)
			break;
	}
}
enum DRINK
{
	WATER = 1,
	COKE,
	FANTA,
	CIDER,
	VITAMIN,
	ULTRA
};

enum STATUS
{
	NOTHING,
	ONE,
	TWO,
	THREE,
	FOUR,
	FIVE,
	ALL
};

void Pro6()
{
	int money = 0, choice;
	int status;

	printf("동전을 넣으시오 (1000, 500, 100 만 가능) : ");
	

	while (1)
	{
		scanf_s("%d", &choice);

		switch (choice)
		{
		case WATER: if (status > NOTHING)	{ money -= 800;	 printf("1. 물 선택\n");}			else printf("잔액 부족\n"); break;
		case COKE: if (status > ONE)		{ money -= 1000; printf("2. 콜라 선택\n");}			else printf("잔액 부족\n"); break;
		case FANTA: if (status > TWO)		{ money -= 1100; printf("3. 환타 선택\n");}			else printf("잔액 부족\n"); break;
		case CIDER: if (status > THREE)		{ money -= 1200; printf("4. 사이다 선택 \n");}		else printf("잔액 부족\n"); break;
		case VITAMIN: if (status > FOUR)	{ money -= 1500; printf("5. 비타민 선택 \n");}		else printf("잔액 부족\n"); break;
		case ULTRA: if (status > FIVE)		{ money -= 2000; printf("6. 울트라 선택 \n");}		else printf("잔액 부족\n"); break;
		case 100: money += 100; break;
		case 500: money += 500; break;
		case 1000: money += 1000; break;
		default:
			printf("적용되는 화폐가 아닙니다.\n\n"); break;
		}

		printf("\n총 금액 : %d \n\n", money);

		// 현재 상태 기록 (하위 목록부터 구매 가능한 갯수에 따라 상태 변경)
		if (money < 800)
			status = NOTHING;
		else if (money < 1000)
			status = ONE;
		else if (money < 1100)
			status = TWO;
		else if (money < 1200)
			status = THREE;
		else if (money < 1500)
			status = FOUR;
		else if (money < 2000)
			status = FIVE;
		else
			status = ALL;

		// 현재 상태에 따른 음료수 메뉴 출력
		switch (status)
		{
		case ALL	: printf("6. 울트라 2000원 \n");
		case FIVE	: printf("5. 비타민 1500원 \n");
		case FOUR	: printf("4. 사이다 1200원 \n");
		case THREE	: printf("3. 환타 1100원 \n");
		case TWO	: printf("2. 콜라 1000원 \n");
		case ONE	: printf("1. 물 800원 \n\n");
		case NOTHING: printf("음료선택 또는 금액 추가 :");  break;
		default:
			break;
		}
	}
}


void main()
{
	//Pro1();
	//Pro2();
	//Pro3();
	//Pro4();
	//Pro5();
	Pro6();
}