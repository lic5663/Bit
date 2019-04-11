#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#pragma warning(disable:4996)
#define TRUE	1
#define FALSE	0


// ���ÿ��� ���������� �ϳ��� �ֿ��� ���� �������� 3���� ������ �迭 ����, �������� ���ڿ���ŭ �����Ҵ�
void pro1()
{
	char **p;
	int n;
	char buf[100];

	printf("���ϴ� ������ ������ �Է��ϼ��� : ");
	scanf("%d", &n);
	getchar();
	
	p = (char**)malloc(sizeof(char*)*n);	// �ʱ� n�� ���� �Ҵ�

	for (int i = 0; i < n; i++)
	{
		gets(buf);
		p[i] = (char*)malloc(strlen(buf) + 1);
		strcpy(p[i], buf);
	}

	for (int i = 0; i < n; i++)
		puts(p[i]);
}


// 

// ���� ����
void shuffle(int arr[])
{
	int shuffle_count = 100;
	int r1, r2 , temp;
	srand((unsigned int)time(NULL));

	for (int i = 1; i <= 25; i++)
	{
		arr[i-1] = i;
	}

	while (shuffle_count)
	{
		r1 = rand() % 25;
		r2 = rand() % 25;

		temp = arr[r1];
		arr[r1] = arr[r2];
		arr[r2] = temp;

		shuffle_count--;
	}
}

// ���� & ��ǻ�� ������ ����
void makeBoard(int dest[5][5], int source[])
{
	int num = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			dest[i][j] = source[num++];
		}
	}
}

// ������ ����
void createBoard(int board[5][5])
{
	int num_arr[25];

	shuffle(num_arr);	// ������ ����
	makeBoard(board, num_arr);
}

// ����&��ǻ�� ������ ��� �Լ�
void printBoard(int user_board[5][5], int com_board[5][5], int *comNum , int *userBingoLineNum ,int *comBingoLineNum)
{
	system("cls");
	printf("\tUSER\t\tCOMPUTER\n");
	printf("--------------------------------------\n");
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (user_board[i][j] > 0)
				printf("%2d ", user_board[i][j]);
			else
				printf("%2c ", 'X');
		}
		printf("\t\t");
		for (int j = 0; j < 5; j++)
		{
			if (com_board[i][j] > 0)
				printf("%2d ", com_board[i][j]);
			else
				printf("%2c ",'X');
		}
		printf("\n");
	}
	printf("--------------------------------------\n");

	printf("userBingo  �� : %d | comBingo �� : %d \n", *userBingoLineNum , *comBingoLineNum);
	printf("--------------------------------------\n");
	if (*comNum > 0)
		printf("computer ���� ���� %d", *comNum);

}

// ���� ��ȣ ���� (����)
int ChoiceNumber(int pool[25])
{
	int choiceNum;
	scanf("%d", &choiceNum);

	for (int i = 0; i < 25; i++)
	{
		if (pool[i] == choiceNum)
		{
			pool[i] = -1;
			return TRUE;
		}	
	}
	return FALSE;
}

// ���� ��ȣ ���� (��ǻ��)
void ComNumber(int pool[25],int * comNum)
{
	
	int choiceNum;
	srand((unsigned int)time(NULL));
	int idx = rand() % 25;

	while (pool[idx]<0)
	{
		++idx;
		if (idx == 25)
			idx = 0;
	}
	choiceNum = pool[idx];
	*comNum = choiceNum;
	pool[idx] = -1;
	return;

}

// �����ǰ� Ǯ�� ���� ��ȣ ����
void NumberDelete(int arr[5][5], int pool[25])
{
	for (int k = 0; k < 25; k++)
	{
		if (pool[k] > 0)
			continue;

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if ((k+1) == arr[i][j])
					arr[i][j] = -1;
			}
		}
	}
	
}

 //bingo �Ǻ�
void bingoCheck(int board[5][5],int *bingoLineNum)
{
	int bingoNum = 0;
	int IsBingo = TRUE;
	// ���� ���� ���� �Ǻ�
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (board[i][j] != -1)	// üũ���� ���� ���ڰ� �����ִ�.
				break;
			if (j == 4)
				bingoNum++;			// ������ üũ�ߴµ� ���߿� ������ ������ �ʾҴ� -> �������
		}
	}

	// ���� ���� ���� �Ǻ�
	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i < 5; i++)
		{
			if (board[i][j] != -1)	// üũ���� ���� ���ڰ� �����ִ�.
				break;
			if (i == 4)
				bingoNum++;			// ������ üũ�ߴµ� ���߿� ������ ������ �ʾҴ� -> �������
		}
	}

	// \ �밢�� ���� ���� �Ǻ�
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i==j)
				if (board[i][j] != -1)	// üũ���� ���� ���ڰ� �����ִ�.
				{
					IsBingo = FALSE;
					break;
				}	
		}
		if (!IsBingo)
			break;
		if (i == 4)
			bingoNum++;			// ������ üũ�ߴµ� ���߿� ������ ������ �ʾҴ� -> �������
	}
	
	IsBingo = TRUE;

	// /�밢�� ���� ���� �Ǻ�
	for (int i = 0; i < 5 ; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if ((i+j)==4)
				if (board[i][j] != -1)	// üũ���� ���� ���ڰ� �����ִ�.
				{
					IsBingo = FALSE;
					break;
				}
		}
		if (!IsBingo)
			break;
		if (i == 4)
			bingoNum++;
	}
	*bingoLineNum = bingoNum;
}

// �¸� ���� Ȯ��
int winCheck(int *userBingoNum, int *comBingoNum)
{
	if (*userBingoNum >= 5)
		return 1;
	else if (*comBingoNum >= 5)
		return -1;
	else
		return 0;
}


// ������ ����, ������ ��ǻ�� ���� , ���ڰ� ������ ���� xǥ, ���� Ȯ�� �� �� ����
void pro2()
{
	int user_board[5][5];		// ���� ������
	int com_board[5][5];		// ��ǻ�� ������
	int numPool[25];			// ���� ���� Ǯ
	int comNum = -1;			// ��ǻ�� ���� ����
	int UserBingoLineNum = 0;	// ���� ���� ���� ��
	int ComBingoLineNum = 0;	// ��ǻ�� ���� ���� ��
	int winStatus;				// �¸� ���ǿ� ���� ���� ����

	for (int i = 1; i <= 25; i++)
	{
		numPool[i - 1] = i;
	}

	createBoard(user_board);
	_sleep(1000);
	createBoard(com_board);
	printBoard(user_board, com_board, &comNum, &UserBingoLineNum, &ComBingoLineNum);

	while (1)
	{
		printf("\n--------------------------------------------------------------------------------\n");
		printf("POOL: ");
		for (int i = 0; i < 25; i++)
		{
			if (numPool[i] > 0)
				printf("%2d ", numPool[i]);
			else
				printf("%2c ",'X');
		}
		printf("\n--------------------------------------------------------------------------------\n");
		
		printf("���ڸ� �Է����ּ��� : ");

		while (!ChoiceNumber(numPool))							// ���� ����
		{
			printf("�ùٸ� ���ڸ� �Է����ּ���\n");
			_sleep(500);
		}

		ComNumber(numPool, &comNum);						// ��ǻ�� ����
		

		NumberDelete(user_board, numPool);
		NumberDelete(com_board, numPool);

		bingoCheck(user_board,&UserBingoLineNum);
		bingoCheck(com_board, &ComBingoLineNum);

		printBoard(user_board, com_board, &comNum, &UserBingoLineNum, &ComBingoLineNum);

		winStatus = winCheck(&UserBingoLineNum, &ComBingoLineNum);
		if (winStatus != 0)
			break;
		
	}

	switch (winStatus)
	{
	case 1: printf("\n\n\nPlayer Win \n"); break;
	case -1 : printf("\n\n\nComputer Win \n"); break;
		
	default:
		break;
	}

}


int main(void)
{
	//pro1();
	pro2();
	return 0;
}