#include <stdio.h>

void Pro1()
{
	int op1, op2;
	printf("�� ���� �Է��Ͻÿ� \n");
	scanf_s("%d %d", &op1, &op2);
	printf("%d�� %d�� ���� �������� %d \n\n", op1, op2, op1%op2);
}

void Pro2()
{
	int n,i;
	int result = 1;
	printf("�ϳ��� ������ �Է��Ͻÿ� \n");
	scanf_s("%d", &n);
	
	for (i = 1; i < 10; i++)
	{
		result *= n;
		printf("%d �� %d ���� %8d \n", n, i, result);
	}
}
void Pro3()
{
	int data;
	printf("shift ������ ���ڸ� �Է��ϼ��� \n");
	scanf_s("%d", &data);
	printf("�Է� ���� �� : %d  �������� 3�� shift �� �� :%d \n",data, data >> 3);
}

void Pro4()
{
	int data;
	printf("3��° ��Ʈ üũ ������ ���ڸ� �Է��ϼ��� \n");
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
	printf("^ ������ ���ڸ� �Է��ϼ��� \n");
	scanf_s("%d", &data);
	temp = data ^ 0xF120;
	printf("1�� ^ ���� ��� : %x \n", temp);
	data = temp ^ 0xF120;
	printf("2�� ^ ���� ��� : %x \n", data);
	
}

void Pro6()
{
	int data1, data2;
	printf("��������� Ȯ�� �� �� ���� �Է��ϼ��� \n");
	scanf_s("%d %d", &data1, &data2);

	if (data1 > 0 && data2 > 0)
		printf("��� ����Դϴ� \n");
	else
		printf("��� ����� �ƴմϴ� \n");
}


int main(void)
{
	//Pro1();
	//Pro2();
	//Pro3();
	//Pro4();
	//Pro5();
	//Pro6();

	// �Է� ����
	getchar();
	getchar();
	return 0;
}