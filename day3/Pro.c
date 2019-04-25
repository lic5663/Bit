#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ���� �������� ��ȯ
char* mystrrev(char *str, int str_len)
{
	char * temp = (char*)malloc(sizeof(char)*str_len);
	for (int i = 0; i < str_len; i++)
	{
		temp[i] = str[str_len - i - 1];
	}
	temp[str_len] = '\0';
	return temp;

}

//void mystrrevTest()
//{
//	char buff[] = "abcd";
//	char *reverse = mystrrev(buff,strlen(buff));
//
//	puts(buff);
//	puts(reverse);
//}

// ��� ����ġ
int numberCompensation(int n)
{
	int decimal = 1;
	for (int i = 0; i < n; i++)
		decimal *= 10;
	return decimal;
}

// ASCII CODE TO INT
int myatoi(char *str, int str_len)
{
	int sum = 0;
	for (int i = 0; i < str_len; i++)
		sum += ((*(str + i) - 48) * numberCompensation(str_len - i - 1));
	
	return sum;
}

//void myatoiTest()
//{
//	printf(" %d \n", myatoi("127", 3));
//}

// INT TO ASCII CODE
void myitoa(int integer, char** str, int system_num)
{
	char temp_str[100] = { 0 };
	int i = 0;
	while (integer)
	{
		temp_str[i] = (integer % system_num) +48;
		integer = integer / system_num;
		i++;
	}
	temp_str[i+1] = '\0';
	*str = mystrrev(temp_str, i);
}


//void myitoaTest()
//{
//	char *buf;
//	myitoa(9187, &buf, 10);
//	puts(buf);
//}

// �ʱ� ���ڸ� �޾Ƽ� �ش� ���� ������ ������ cycle��ŭ �ݺ��Ѵ�.
void calculator(int cycle, int data)
{
	int sum = 0;
	int var = 0;
	char * temp;

	while (cycle)
	{
		myitoa(data, &temp, 10);
		temp = mystrrev(temp, strlen(temp));
		var = myatoi(temp,strlen(temp));
		sum = data + var;

		printf("\t%d\n+\t%d\n----------------\n\t%d\n\n", data, var, sum);

		data = sum;
		cycle--;
	}
}

void calculatorTest()
{
	int cycle;
	int data;

	printf("�ݺ� ����Ŭ�� ���ڸ� �Է����ּ��� \n");
	scanf_s("%d %d", &cycle, &data);
	calculator(cycle, data);
}

void main()
{
	//mystrrevTest();
	//myatoiTest();
	//myitoaTest();
	calculatorTest();
	getchar();
}

//
//void Pro_main()
//{
//	char buff[] = "abcd";
//
//	mystrrev(buff); // ���ڿ��� ������ �Լ� -> dcba ,mystrrev(buff, n) ���ڿ� �ް� n��ŭ ������ ���� ���ڿ� ���Ѵ�.
//	puts(buff);
//
//	int num;
//	num = myatoi("123");  // ���ڿ��� ���� ������ ��ȯ�ϴ� �Լ�
//	printf("%d \n", num);
//
//	myitoa(456, buff, 10); // int�� ���� 10���� ���·� buff�� �־� ���ڿ��� ����
//	puts(buff);
//}