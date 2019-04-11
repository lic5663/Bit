#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#pragma warning(disable:4996)
#define TRUE	1
#define FALSE	0
#define NAME_MAX_LEN 100

enum GAME_STATUS
{
	NOTHING = 0,
	DRAW,
	WIN,
	LOOSE
};

// �÷��̾� ����ü
typedef struct __Player
{
	char	name[NAME_MAX_LEN];
	int		selectNum;
	int		bingoLine;
	int		board[5][5];
	int		status;

}Player;

// �÷��̾� �ʱ�ȭ
void PlayerInit(Player *player, char * name)
{
	strcpy(player->name, name);
	player->selectNum = -1;
	player->bingoLine = 0;
	player->status = 0;
}

// ���� ����
void shuffle(int arr[])
{
	int shuffle_count = 100;
	int r1, r2, temp;
	srand((unsigned int)time(NULL));

	for (int i = 1; i <= 25; i++)
	{
		arr[i - 1] = i;
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
void createBoard(Player * player)
{
	int num_arr[25];

	shuffle(num_arr);	// ������ ����
	makeBoard(player->board, num_arr);
}

// ����&��ǻ�� ������ ��� �Լ�
void printBoard(Player *user, Player *com, int numPool[25])
{
	system("cls");
	printf("\t%s\t\t%s\n",user->name, com->name);
	printf("--------------------------------------\n");
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if ((user->board)[i][j] > 0)
				printf("%2d ", (user->board)[i][j]);
			else
				printf("%2c ", 'X');
		}
		printf("\t\t");
		for (int j = 0; j < 5; j++)
		{
			if ((com->board)[i][j] > 0)
				printf("%2d ", (com->board)[i][j]);
			else
				printf("%2c ", 'X');
		}
		printf("\n");
	}
	printf("--------------------------------------\n");

	printf("userBingo  �� : %d | comBingo �� : %d \n", user->bingoLine, com->bingoLine);
	printf("--------------------------------------\n");
	if (com->selectNum > 0)
		printf("computer ���� ���� %d", com->selectNum);

	printf("\n--------------------------------------------------------------------------------\n");
	printf("POOL: ");
	for (int i = 0; i < 25; i++)
	{
		if (numPool[i] > 0)
			printf("%2d ", numPool[i]);
		else
			printf("%2c ", 'X');
	}
	printf("\n--------------------------------------------------------------------------------\n");

	printf("���ڸ� �Է����ּ��� : ");

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

// ��ȣ ���� (��ǻ��)
void ComNumber(int pool[25], Player *com)
{
	int choiceNum;
	srand((unsigned int)time(NULL));
	int idx = rand() % 25;

	while (pool[idx] < 0)
	{
		++idx;
		if (idx == 25)
			idx = 0;
	}
	choiceNum = pool[idx];
	 com->selectNum = choiceNum;
	pool[idx] = -1;
	return;

}

// �����ǰ� Ǯ�� ���� ��ȣ ����
void NumberDelete(Player *player, int pool[25])
{
	for (int k = 0; k < 25; k++)
	{
		if (pool[k] > 0)
			continue;

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if ((k + 1) == (player->board)[i][j])
					(player->board)[i][j] = -1;
			}
		}
	}
}

//bingo �Ǻ�
void bingoCheck(Player *player)
{
	int bingoNum = 0;
	int IsBingo = TRUE;
	// ���� ���� ���� �Ǻ�
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if ((player->board)[i][j] != -1)	// üũ���� ���� ���ڰ� �����ִ�.
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
			if ((player->board)[i][j] != -1)	// üũ���� ���� ���ڰ� �����ִ�.
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
			if (i == j)
				if ((player->board)[i][j] != -1)	// üũ���� ���� ���ڰ� �����ִ�.
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
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if ((i + j) == 4)
				if ((player->board)[i][j] != -1)	// üũ���� ���� ���ڰ� �����ִ�.
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
	player->bingoLine = bingoNum;
}

// �¸� ���� Ȯ��
void winCheck(Player *player)
{
	if (player->bingoLine >= 5)
	{
		player->status = WIN;
		return;
	}
	else
	{
		player->status = NOTHING;
		return;
	}	
}

int AfterSelectNumProcess(Player * user, Player * com, int numPool[25])
{
	NumberDelete(user, numPool);
	NumberDelete(com, numPool);

	bingoCheck(user);
	bingoCheck(com);

	winCheck(user);
	winCheck(com);

	if (user->status == WIN && com->status == WIN)
		return DRAW;
	else if (user->status == WIN)
		return WIN;
	else if (com->status == WIN)
		return LOOSE;
	else
		return NOTHING;
}


// ������ ����, ������ ��ǻ�� ���� , ���ڰ� ������ ���� xǥ, ���� Ȯ�� �� �� ����
void pro2()
{
	int numPool[25];			// ���� ���� Ǯ
	int winStatus = 0;

	Player *user	= (Player*)malloc(sizeof(Player));
	Player *com		= (Player*)malloc(sizeof(Player));

	PlayerInit(user, "USER");	// �� �÷��̾� ���� �ʱ�ȭ
	PlayerInit(com, "COM");

	// ���� Ǯ ����
	for (int i = 1; i <= 25; i++)
	{
		numPool[i - 1] = i;
	}

	// �÷��̾� & ��ǻ�� ������ ����
	createBoard(user);
	_sleep(1000);
	createBoard(com);

	printBoard(user, com, numPool);

	while (1)
	{
		
		while (!ChoiceNumber(numPool))							// ���� ����
		{
			printf("�ùٸ� ���ڸ� �Է����ּ���\n");
			_sleep(500);
		}

		if (winStatus = AfterSelectNumProcess(user, com, numPool))
		{
			printBoard(user, com, numPool);
			break;
		}

		ComNumber(numPool, com);						// ��ǻ�� ����

		if (winStatus = AfterSelectNumProcess(user, com, numPool))
		{
			printBoard(user, com, numPool);
			break;
		}

		printBoard(user, com, numPool);
	}

	switch (winStatus)
	{
	case WIN: printf("\n\n\n Player Win \n"); break;
	case LOOSE: printf("\n\n\n Computer Win \n"); break;
	case DRAW: printf("\n\n\n DRAW \n"); break;

	default:
		break;
	}
}

int main(void)
{
	pro2();
	return 0;
}