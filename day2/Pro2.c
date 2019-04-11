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
	// a �迭 ���� ���� ū ���� ã�� ����ϴ� ���α׷�
	int max = 0;
	for (int i = 0; i < 5; i++)
	{
		if (max < a[i])
			max = a[i];
	}
	printf("���� ū �� : %d \n", max);
}

void Pro3()
{
	int a[height][width] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	int horizontal_sum = 0;
	int vertical_sum[width] = { 0 };
	// �迭 a�� ���� ��� ���� ������ ���Ͽ� ������ ���� ���
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
		printf("���̸� �Է��ϼ��� : ");
		scanf_s("%d", &answer);

		if (first)
			pre_answer = answer;

		if (answer == age)
		{
			printf("�����Դϴ�. %d�� ���� ���߼̽��ϴ� \n", count);
			break;
		}

		if (answer < age)
		{
			if (flag == -1 && pre_answer > answer)
				printf("�� ���������� ���� ���� �����̽��ϱ�.\n");
			else
			{
				printf("�׺��� ���̰� �����ϴ� \n");
				pre_answer = answer;
				flag = -1;
			}
		}
		if (answer > age)
		{
			if (flag == 1 && pre_answer < answer)
				printf("�� ���������� ū ���� �����̽��ϱ�.\n");
			else
			{
				printf("�׺��� ���̰� �����ϴ� \n");
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

	printf("������ �����ÿ� (1000, 500, 100 �� ����) : ");
	

	while (1)
	{
		scanf_s("%d", &choice);

		switch (choice)
		{
		case WATER: if (status > NOTHING)	{ money -= 800;	 printf("1. �� ����\n");}			else printf("�ܾ� ����\n"); break;
		case COKE: if (status > ONE)		{ money -= 1000; printf("2. �ݶ� ����\n");}			else printf("�ܾ� ����\n"); break;
		case FANTA: if (status > TWO)		{ money -= 1100; printf("3. ȯŸ ����\n");}			else printf("�ܾ� ����\n"); break;
		case CIDER: if (status > THREE)		{ money -= 1200; printf("4. ���̴� ���� \n");}		else printf("�ܾ� ����\n"); break;
		case VITAMIN: if (status > FOUR)	{ money -= 1500; printf("5. ��Ÿ�� ���� \n");}		else printf("�ܾ� ����\n"); break;
		case ULTRA: if (status > FIVE)		{ money -= 2000; printf("6. ��Ʈ�� ���� \n");}		else printf("�ܾ� ����\n"); break;
		case 100: money += 100; break;
		case 500: money += 500; break;
		case 1000: money += 1000; break;
		default:
			printf("����Ǵ� ȭ�� �ƴմϴ�.\n\n"); break;
		}

		printf("\n�� �ݾ� : %d \n\n", money);

		// ���� ���� ��� (���� ��Ϻ��� ���� ������ ������ ���� ���� ����)
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

		// ���� ���¿� ���� ����� �޴� ���
		switch (status)
		{
		case ALL	: printf("6. ��Ʈ�� 2000�� \n");
		case FIVE	: printf("5. ��Ÿ�� 1500�� \n");
		case FOUR	: printf("4. ���̴� 1200�� \n");
		case THREE	: printf("3. ȯŸ 1100�� \n");
		case TWO	: printf("2. �ݶ� 1000�� \n");
		case ONE	: printf("1. �� 800�� \n\n");
		case NOTHING: printf("���ἱ�� �Ǵ� �ݾ� �߰� :");  break;
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