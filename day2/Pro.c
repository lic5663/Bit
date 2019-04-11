#include <stdio.h>


void Pro1()
{
	int a = 0xA5;
	int reverse = 0x0;
	int p;

	if (a & (1 << 6))
		puts("true \n");
	else
		puts("false \n");

	p = a | ((1 << 3) + (1 << 1));
	printf("%x \n", p);

	p &= ~((1 << 2) + (1 << 1));
	printf("%x \n", p);

	p &= ((1 << 5) + (1 << 6) + (1 << 7));
	printf("%x \n\n", p);

	a = 0x12345678;
	printf("%x \n", a);

	p = a & 0xFF000000;
	reverse += (p >> 24);

	p = a & 0x00FF0000;
	reverse += (p >> 8);

	p = a & 0x0000FF00;
	reverse += (p << 8);

	p = a & 0x000000FF;
	reverse += (p << 24);

	printf("%x \n", reverse);
}

// � ���̵��� 4�� ����� ���
void Pro2()
{
	int i;
	int j;
	int output;

	for (i = 0; i < 105; i++)
	{
		output = i + 3;
		output &= ~(3);
		printf("%d ", output);
	}
}

// data�� �Է¹޾Ƽ� n��° bit�������� w��ŭ�� bit�� �������� ���
void Pro3()
{
	int data;
	int temp;
	int n, w;
	int masking = 0xFFFFFF;

	scanf_s("%d", &data);
	scanf_s("%d %d",&n,&w);

	data = (data >> (n-1));
	masking = (masking >> w);
	masking = (masking << w);

	data = data & ~(masking);

	printf("%x \n", data);

}

void Pro4()
{
	char ch;

	while ((ch = getchar()) != EOF)
	{
		if (ch >= 'A' && ch <= 'Z') // A : 65 , a : 97,  0: 48

		{
			printf("�빮�� , �ҹ��� ��ȯ�� %c \n ",ch+32);
		}
		else if (ch >= 'a' && ch <= 'z')
		{
			printf("�ҹ��� , �빮�� ��ȯ�� %c \n", ch-32);
		}
		else
			printf("���ĺ� �ƴ� \n");
		getchar();
	}
	
}

void main()
{
	//Pro1();
	//Pro2();
	//Pro3();
	//Pro4();

}