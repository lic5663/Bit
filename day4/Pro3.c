#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#pragma warning(disable:4996)
#define TRUE	1
#define FALSE	0


// 스택영역 더블포인터 하나가 주워진 형태 힙공간에 3개의 포인터 배열 생성, 힙공간에 문자열만큼 동적할당
void pro1()
{
	char **p;
	int n;
	char buf[100];

	printf("원하는 문장의 갯수를 입력하세요 : ");
	scanf("%d", &n);
	getchar();
	
	p = (char**)malloc(sizeof(char*)*n);	// 초기 n개 영역 할당

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

// 숫자 섞기
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
void createBoard(int board[5][5])
{
	int num_arr[25];

	shuffle(num_arr);	// 데이터 셔플
	makeBoard(board, num_arr);
}

// 유저&컴퓨터 빙고판 출력 함수
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

	printf("userBingo  수 : %d | comBingo 수 : %d \n", *userBingoLineNum , *comBingoLineNum);
	printf("--------------------------------------\n");
	if (*comNum > 0)
		printf("computer 선택 숫자 %d", *comNum);

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

// 선택 번호 제거 (컴퓨터)
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

// 보드판과 풀을 비교해 번호 제거
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

 //bingo 판별
void bingoCheck(int board[5][5],int *bingoLineNum)
{
	int bingoNum = 0;
	int IsBingo = TRUE;
	// 가로 라인 빙고 판별
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (board[i][j] != -1)	// 체크하지 않은 숫자가 남아있다.
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
			if (board[i][j] != -1)	// 체크하지 않은 숫자가 남아있다.
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
			if (i==j)
				if (board[i][j] != -1)	// 체크하지 않은 숫자가 남아있다.
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
	for (int i = 0; i < 5 ; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if ((i+j)==4)
				if (board[i][j] != -1)	// 체크하지 않은 숫자가 남아있다.
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

// 승리 조건 확인
int winCheck(int *userBingoNum, int *comBingoNum)
{
	if (*userBingoNum >= 5)
		return 1;
	else if (*comBingoNum >= 5)
		return -1;
	else
		return 0;
}


// 빙고판 제작, 유저와 컴퓨터 대전 , 각자가 선택한 수는 x표, 빙고 확인 승 패 결정
void pro2()
{
	int user_board[5][5];		// 유저 빙고판
	int com_board[5][5];		// 컴퓨터 빙고판
	int numPool[25];			// 공용 숫자 풀
	int comNum = -1;			// 컴퓨터 선택 숫자
	int UserBingoLineNum = 0;	// 유저 빙고 라인 수
	int ComBingoLineNum = 0;	// 컴퓨터 빙고 라인 수
	int winStatus;				// 승리 조건에 따른 현재 상태

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
		
		printf("숫자를 입력해주세요 : ");

		while (!ChoiceNumber(numPool))							// 유저 선택
		{
			printf("올바른 숫자를 입력해주세요\n");
			_sleep(500);
		}

		ComNumber(numPool, &comNum);						// 컴퓨터 선택
		

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