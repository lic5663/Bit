#include<stdio.h>
#include<string.h>
#pragma warning (disable:4996)

//���� ����ü�� ���̺귯�� qsort�� ����Ͽ� itemname�� ������������ �����Ͻÿ�
typedef struct _sales
{
	char itemname[20];
	int unitprice;
	int count;
	int amount;
}Sales;
int prd_item(const void *a, const void *b)
{
	return strcmp(((Sales*)a)->itemname, ((Sales*)b)->itemname);
}
main()
{
	Sales prd[5] = {
	 { "ccc", 10,90,900 },
	{ "aaa", 20,80,1600 },
	{ "ddd", 30,70,2100 },
	{ "eee", 40,60,2400 },
	{ "bbb", 50,50,2500 }
	};
	int dx;

	qsort(prd, 5, sizeof(prd[0]), prd_item);


	for (dx = 0; dx < 5; dx++)
		printf("%s %d %d %d\n", prd[dx].itemname, prd[dx].unitprice, prd[dx].count, prd[dx].amount);


}