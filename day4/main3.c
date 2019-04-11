#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 100
#pragma warning(disable:4996)

main()
{
	FILE *wp, *rp, *rp2,*wp2;
	int cnt;
	int temp=0;
	int total = 0;
	char buf[100];
	rp = fopen("1.jpg", "rb");
	wp = fopen("2.jpg", "wb");
	rp2 = fopen("1.jpg", "rb");
	wp2 = fopen("3.jpg", "wb");

	// 한바이트 읽고 한 바이트 쓰기

	// 한줄 읽고 한줄 쓰기

	// 원하는 만큼 읽고 원하는 만큼 쓰기
	while (1)
	{
		cnt = fread(buf, sizeof(char), 100, rp);

		if (cnt < 100)
		{
			//두가지의 경우 cnt가 100보다 작다.
			if (feof(rp))	// 끝부분 에서만 0이 아닌 값을 반환한다.
			{	// 파일 끝까지 도달
				total +=  fwrite(buf, sizeof(char), cnt, wp);
				printf("총  %d  복사 완료 ",total);
			}
			else
				puts("복사 실패");
			break;
		}
		total += fwrite(buf, sizeof(char), 100, wp);
	}

	while (temp<total/2)
	{
		cnt = fread(buf, sizeof(char), 100, rp2);
		temp += cnt;
		if (cnt < 100)
		{
			//두가지의 경우 cnt가 100보다 작다.
			if (feof(rp2))	// 끝부분 에서만 0이 아닌 값을 반환한다.
			{	// 파일 끝까지 도달
				fwrite(buf, sizeof(char), cnt, wp2);
				//printf("총  %d  복사 완료 ", total);
			}
			else
				puts("복사 실패");
			break;
		}
		fwrite(buf, sizeof(char), 100, wp2);
	}
	

	fclose(rp);
	fclose(wp);
	fclose(wp2);
}


/*
int main(void)
{

	FILE *fwp, *frp;
	fwp = fopen("a.txt", "w");			// 출력 스트림
	fprintf(fwp, "%d %c ", 123, 'A');
	fclose(fwp);


	int num;
	char ch;
	frp = fopen("a.txt", "r");			// 입력 스트림
	fscanf(frp, "%d %c", &num, &ch);
	fclose(frp);
	printf("%d %c\n", num, ch);

	FILE *fap;
	fap = fopen("a.txt", "a");			// 추가 출력 스트림
	fprintf(fap,  "%s \n", "이인찬");
	fclose(fap);

	char arr[100];
	frp = fopen("a.txt", "r");			// 입력 스트림
	fscanf(frp, "%d %c %s", &num, &ch, arr);
	fclose(frp);

	printf("%d %c %s \n", num, ch , arr);


	return 0;
}
*/