#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 100
#pragma warning(disable:4996)


// 자신의 주소를 입력받아서 딱맞는 주소의 크기만큼을 힙에 할당하고 넣은 뒤 출력하시오
void dynamicMemory()
{
	char buffer[MAX_LEN];
	printf("주소를 입력하시오\n");
	gets_s(buffer, MAX_LEN);
	
	char * ch = (char*)malloc(strlen(buffer)+1);	//널문자 고려 공간 필요 +1
	strcpy_s(ch, strlen(buffer)+1 ,buffer);

	puts(ch);
	free(ch);										// 널문자 고려 안할시 종료 오래걸림
}

int main(void)
{
	int *p;
	p = malloc(4);		// 4바이트 메모리를 힙 영역에 잡고 주소를 리턴

	//int a;			// 위와 동일 형태 단) stack 영역에 둘다 존재
	//int *p;
	//p = &a; 
	//printf("%d", *p);

	int a[5];
	int *q = a;

	int *r;
	r = (int*)malloc(5 * sizeof(int));

	dynamicMemory();
	
	return 0;
}