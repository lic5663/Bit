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

	// �ѹ���Ʈ �а� �� ����Ʈ ����

	// ���� �а� ���� ����

	// ���ϴ� ��ŭ �а� ���ϴ� ��ŭ ����
	while (1)
	{
		cnt = fread(buf, sizeof(char), 100, rp);

		if (cnt < 100)
		{
			//�ΰ����� ��� cnt�� 100���� �۴�.
			if (feof(rp))	// ���κ� ������ 0�� �ƴ� ���� ��ȯ�Ѵ�.
			{	// ���� ������ ����
				total +=  fwrite(buf, sizeof(char), cnt, wp);
				printf("��  %d  ���� �Ϸ� ",total);
			}
			else
				puts("���� ����");
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
			//�ΰ����� ��� cnt�� 100���� �۴�.
			if (feof(rp2))	// ���κ� ������ 0�� �ƴ� ���� ��ȯ�Ѵ�.
			{	// ���� ������ ����
				fwrite(buf, sizeof(char), cnt, wp2);
				//printf("��  %d  ���� �Ϸ� ", total);
			}
			else
				puts("���� ����");
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
	fwp = fopen("a.txt", "w");			// ��� ��Ʈ��
	fprintf(fwp, "%d %c ", 123, 'A');
	fclose(fwp);


	int num;
	char ch;
	frp = fopen("a.txt", "r");			// �Է� ��Ʈ��
	fscanf(frp, "%d %c", &num, &ch);
	fclose(frp);
	printf("%d %c\n", num, ch);

	FILE *fap;
	fap = fopen("a.txt", "a");			// �߰� ��� ��Ʈ��
	fprintf(fap,  "%s \n", "������");
	fclose(fap);

	char arr[100];
	frp = fopen("a.txt", "r");			// �Է� ��Ʈ��
	fscanf(frp, "%d %c %s", &num, &ch, arr);
	fclose(frp);

	printf("%d %c %s \n", num, ch , arr);


	return 0;
}
*/