#include <stdio.h>

void Pro1()
{
	int op1, op2;
	printf("두 수를 입력하시오 \n");
	scanf_s("%d %d", &op1, &op2);
	printf("%d를 %d로 나눈 나머지는 %d \n\n", op1, op2, op1%op2);
}

void Pro2()
{
	int n,i;
	int result = 1;
	printf("하나의 정수를 입력하시오 \n");
	scanf_s("%d", &n);
	
	for (i = 1; i < 10; i++)
	{
		result *= n;
		printf("%d 의 %d 승은 %8d \n", n, i, result);
	}
}
void Pro3()
{
	int data;
	printf("shift 연산할 숫자를 입력하세요 \n");
	scanf_s("%d", &data);
	printf("입력 받은 수 : %d  왼쪽으로 3번 shift 한 수 :%d \n",data, data >> 3);
}

void Pro4()
{
	int data;
	printf("3번째 비트 체크 연산할 숫자를 입력하세요 \n");
	scanf_s("%d", &data);
	if (data & (1 << 2))
		printf("True \n");
	else
		printf("False \n");
}

void Pro5()
{
	int data;
	int temp;
	printf("^ 연산할 숫자를 입력하세요 \n");
	scanf_s("%d", &data);
	temp = data ^ 0xF120;
	printf("1차 ^ 연산 결과 : %x \n", temp);
	data = temp ^ 0xF120;
	printf("2차 ^ 연산 결과 : %x \n", data);
	
}

void Pro6()
{
	int data1, data2;
	printf("양수인지를 확인 할 두 수를 입력하세요 \n");
	scanf_s("%d %d", &data1, &data2);

	if (data1 > 0 && data2 > 0)
		printf("모두 양수입니다 \n");
	else
		printf("모두 양수는 아닙니다 \n");
}


int main(void)
{
	//Pro1();
	//Pro2();
	//Pro3();
	//Pro4();
	//Pro5();
	//Pro6();

	// 입력 대기용
	getchar();
	getchar();
	return 0;
}