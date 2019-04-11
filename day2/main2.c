#include <stdio.h>
#pragma warning(disable:4996)  // 새문법을 쓰지않겟다.

int get_num()
{
	return 40;
}

void main()
{
	int a[100];		//a[0] ~ a[99] 배열이 속도 측면에선 매우 좋다.

	// 1차원 배여로 문자열 처리 가능
	char arr[] = "abc";				// 4
	char brr[4] = "abc";			// 4
	char crr[] = { 'a','b','c' };	// 3
	char drr[4] = { 'a','b','c' };	// 4 초기화 리스트의 개수가 모자를때 나머진 0

	char err[2][10] = { "aaa","bbbb" };

	printf("%s \n", arr);
	printf("%s \n", brr);
	printf("%s \n", crr);
	printf("%s \n", drr);
	printf("%s \n", err[0]);
	printf("%s \n", err[1]);

	// a, b, d는 동일 상태로 본다. 


	//간접 연산자
	int n = 10; // 변수를 정하면서 초기화
	n = 20; // 대입연산자를 이용한 대입
	scanf_s("%d", &n);	// 키보드 입력(표준입력)을 통한 입력
	n = get_num();		// 함수의 리턴값을 n에 대입
	*&n = 50;
	printf("%d %d \n", n, *&n);
 }