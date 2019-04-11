#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 정수 역순으로 변환
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

// 배수 보정치
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

// 초기 인자를 받아서 해당 수의 역순과 덧셈을 cycle만큼 반복한다.
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

	printf("반복 사이클과 인자를 입력해주세요 \n");
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
//	mystrrev(buff); // 문자열을 뒤집는 함수 -> dcba ,mystrrev(buff, n) 문자열 받고 n만큼 뒤집고 기존 숫자와 더한다.
//	puts(buff);
//
//	int num;
//	num = myatoi("123");  // 문자열을 실제 정수로 변환하는 함수
//	printf("%d \n", num);
//
//	myitoa(456, buff, 10); // int형 값을 10진수 형태로 buff에 넣어 문자열로 변경
//	puts(buff);
//}