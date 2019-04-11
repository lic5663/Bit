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

// 플레이어 구조체
typedef struct __Player
{
	char	name[NAME_MAX_LEN];
	int		selectNum;
	int		bingoLine;
	int		board[5][5];
	int		status;

}Player;

// 플레이어 초기화
void PlayerInit(Player *player, char * name)
{
	strcpy(player->name, name);
	player->selectNum = -1;
	player->bingoLine = 0;
	player->status = 0;
}

// 숫자 섞기
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

// 유저 & 컴퓨터 빙고판 제작
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

// 보드판 생성
void createBoard(Player * player)
{
	int num_arr[25];

	shuffle(num_arr);	// 데이터 셔플
	makeBoard(player->board, num_arr);
}

// 유저&컴퓨터 빙고판 출력 함수
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

	printf("userBingo  수 : %d | comBingo 수 : %d \n", user->bingoLine, com->bingoLine);
	printf("--------------------------------------\n");
	if (com->selectNum > 0)
		printf("computer 선택 숫자 %d", com->selectNum);

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

	printf("숫자를 입력해주세요 : ");

}

// 선택 번호 제거 (유저)
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

// 번호 선택 (컴퓨터)
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

// 보드판과 풀을 비교해 번호 제거
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

//bingo 판별
void bingoCheck(Player *player)
{
	int bingoNum = 0;
	int IsBingo = TRUE;
	// 가로 라인 빙고 판별
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if ((player->board)[i][j] != -1)	// 체크하지 않은 숫자가 남아있다.
				break;
			if (j == 4)
				bingoNum++;			// 끝까지 체크했는데 도중에 문제가 생기지 않았다 -> 빙고라인
		}
	}

	// 세로 라인 빙고 판별
	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i < 5; i++)
		{
			if ((player->board)[i][j] != -1)	// 체크하지 않은 숫자가 남아있다.
				break;
			if (i == 4)
				bingoNum++;			// 끝까지 체크했는데 도중에 문제가 생기지 않았다 -> 빙고라인
		}
	}

	// \ 대각선 라인 빙고 판별
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i == j)
				if ((player->board)[i][j] != -1)	// 체크하지 않은 숫자가 남아있다.
				{
					IsBingo = FALSE;
					break;
				}
		}
		if (!IsBingo)
			break;
		if (i == 4)
			bingoNum++;			// 끝까지 체크했는데 도중에 문제가 생기지 않았다 -> 빙고라인
	}

	IsBingo = TRUE;

	// /대각선 라인 빙고 판별
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if ((i + j) == 4)
				if ((player->board)[i][j] != -1)	// 체크하지 않은 숫자가 남아있다.
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

// 승리 조건 확인
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


// 빙고판 제작, 유저와 컴퓨터 대전 , 각자가 선택한 수는 x표, 빙고 확인 승 패 결정
void pro2()
{
	int numPool[25];			// 공용 숫자 풀
	int winStatus = 0;

	Player *user	= (Player*)malloc(sizeof(Player));
	Player *com		= (Player*)malloc(sizeof(Player));

	PlayerInit(user, "USER");	// 각 플레이어 상태 초기화
	PlayerInit(com, "COM");

	// 숫자 풀 생성
	for (int i = 1; i <= 25; i++)
	{
		numPool[i - 1] = i;
	}

	// 플레이어 & 컴퓨터 보드판 생성
	createBoard(user);
	_sleep(1000);
	createBoard(com);

	printBoard(user, com, numPool);

	while (1)
	{
		
		while (!ChoiceNumber(numPool))							// 유저 선택
		{
			printf("올바른 숫자를 입력해주세요\n");
			_sleep(500);
		}

		if (winStatus = AfterSelectNumProcess(user, com, numPool))
		{
			printBoard(user, com, numPool);
			break;
		}

		ComNumber(numPool, com);						// 컴퓨터 선택

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