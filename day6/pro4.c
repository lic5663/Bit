#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning (disable:4996)
#define NAME_LEN 100
#define TRUE	1
#define FALSE	0
//typedef int(*fcmp)(void *, void *);

enum MENU
{
	PRINT = 1,
	FILEOUT,
	FIND,
	DELETE,
	ARRAY,
	SORT,
	EXIT
};

typedef struct _product
{
	struct _product *next;	// 다음 제품
	char *name;				// 제품명
	int unit_price;			// 단가
	int quantity;			// 개수
	int price;				// 총금액
}Product;

typedef struct _list
{
	Product * head;
	Product * tail;
	Product * cur;
	Product * pre;

	int numberOfProduct;
	int sum;
}List;

// 리스트 초기화
void InitList(List * plist)
{
	Product * headProduct = (Product*)malloc(sizeof(Product));
	Product * tailProduct = (Product*)malloc(sizeof(Product));

	plist->head = headProduct;
	plist->tail = tailProduct;

	plist->head->next = plist->tail;
	plist->tail->next = plist->tail;

	plist->cur = plist->head;
	plist->pre = plist->head;
	plist->numberOfProduct = 0;
	plist->sum = 0;
}


// 배열데이터를 리스트에 삽입
void addArrData(List * plist, Product **pArr)
{
	int i = 0;
	plist->head->next = plist->tail;
	plist->cur = plist->head;
	while (i < plist->numberOfProduct)
	{
		Product * newProduct = pArr[i];
		newProduct->next = plist->cur->next;
		plist->cur->next = newProduct;

		i++;
		plist->cur = plist->cur->next;
	}
}

// item.txt 데이터 리스트에 삽입 함수
void addItemData(List * plist, char * name, int u_price)
{
	Product * newProduct = (Product*)malloc(sizeof(Product));
	char * productName = (char*)malloc(strlen(name) + 1);
	strcpy(productName, name);
	newProduct->name = productName;
	newProduct->unit_price = u_price;

	// 헤드 다음에 새로운 데이터를 삽입한다.
	newProduct->next = plist->head->next;
	plist->head->next = newProduct;
	(plist->numberOfProduct)++;
}

// item.txt 파일 읽어오기
void ReadItem(List *plist)
{
	FILE *fp = fopen("item.txt", "r");

	char product_name[100];
	int unit_price;

	while (!feof(fp))
	{
		fscanf(fp, "%s %d", product_name, &unit_price);
		addItemData(plist, product_name, unit_price);
	}

	fclose(fp);
}

// 데이터 검색 (이름으로 검색) 데이터가 존재하면 TRUE 반환, 없으면 FALSE 반환
int FindProduct(List * plist, char * name)
{
	plist->pre = plist->head;
	plist->cur = plist->head->next;
	while (plist->cur != plist->tail)
	{
		if (strcmp((plist->cur->name), name) == 0)
			return TRUE;
		

		plist->pre = plist->pre->next;
		plist->cur = plist->cur->next;
	}
	return FALSE;
}

// sales 데이터 리스트에 추가
void addSalesData(List * plist, char *name, int quantity)
{
	if (FindProduct(plist,name))
	{
		Product * product = plist->cur;
		product->quantity = quantity;
		product->price = (product->quantity * product->unit_price);
		plist->sum += product->price;
		return;
	}
	else
		printf("대상 상품은 존재하지 않습니다 \n");
	return;
}

// sales.txt 데이터 읽어오기
void ReadSales(List *plist)
{
	FILE *fp = fopen("sales.txt", "r");

	char product_name[100];
	int product_quantity;

	while (!feof(fp))
	{
		fscanf(fp, "%s %d", product_name, &product_quantity);
		addSalesData(plist, product_name, product_quantity);
	}

	fclose(fp);
}

void PrintData(List *plist)
{
	Product * curProduct = plist->head->next;
	printf(" ============================================\n");
	printf(" \t삼성전자 온라인 매출 현황\n");
	printf(" ============================================\n");
	printf(" \t상품명\t   단가\t   개수\t   금액\n");
	printf(" --------------------------------------------\n");


	while (curProduct != plist->tail)
	{
		printf("%14s\t%7d\t%7d\t%7d \n", curProduct->name, curProduct->unit_price,curProduct->quantity,curProduct->price);
		curProduct = curProduct->next;
	}
	printf("\n");
}

// output.txt 파일로 내부 데이터 방출
void FileOut(List * plist)
{
	FILE *fp = fopen("output.txt", "w");
	Product *writer = plist->head->next;
	while (writer != plist->tail)
	{
		fprintf(fp, "%s %d %d %d\n", writer->name, writer->unit_price, writer->quantity, writer->price);
		writer = writer->next;
	}
	fclose(fp);

	printf("데이터 내보내기를 성공적으로 완료했습니다.\n");
}

int PrintMenu()
{
	int n = 0;
	printf("===== M E N U =====\n");
	printf("1. 매출현황 출력\n");
	printf("2. 매출현황 내보내기\n");
	printf("3. 상품 찾기\n");
	printf("4. 상품 삭제\n");
	printf("5. 매출현황 배열\n");
	printf("6. 정렬\n");
	printf("7. 종료\n");
	printf("===================\n");

	while (n < 1 || n>8)
	{
		printf("메뉴를 선택하시오 : ");
		scanf("%d", &n);
	}
	getchar();
	return n;
}

void Find(List * plist)
{
	char productName[100];
	printf("검색할 품목의 이름을 입력해주세요 : ");
	gets(productName);
	
	if (FindProduct(plist, productName))
	{
		Product * find = plist->cur;
		printf("검색된 항목 : %s %d %d %d \n", find->name, find->unit_price, find->quantity, find->price);
		return;
	}
}

void DeleteProduct(List * plist)
{
	char productName[100];
	printf("삭제할 품목의 이름을 입력해주세요 : ");
	gets(productName);

	if (FindProduct(plist, productName))
	{
		Product * dProduct = plist->cur;
		plist->pre->next = plist->cur->next;
		
		printf("삭제된 항목 : %s %d %d %d \n", dProduct->name, dProduct->unit_price, dProduct->quantity, dProduct->price);
		(plist->numberOfProduct)--;
		free(dProduct);
		return;
	}

}




void arrayView(List * plist, Product ** pArr)
{
	printf(" ============================================\n");
	printf(" \t삼성전자 온라인 매출 현황\n");
	printf(" ============================================\n");
	printf(" \t상품명\t   단가\t   개수\t   금액\n");
	printf(" --------------------------------------------\n");

	for (int i = 0; i < plist->numberOfProduct; i++)
	{
		printf("%14s\t%7d\t%7d\t%7d \n", pArr[i]->name, pArr[i]->unit_price, pArr[i]->quantity, pArr[i]->price);
	}
	printf("\n");
}

void arraySave(List * plist, Product ** pArr)
{
	int i = 0;
	Product * temp = plist->head->next;

	while (temp != plist->tail)
	{
		pArr[i] = temp;

		i++;
		temp = temp->next;
	}
	//arrayView(plist, pArr);
}


int cmp_name(const void *p, const void*k)
{
	return strcmp( (*((Product**)p))->name  , (*((Product**)k))->name);
}

int cmp_unitPrice(const void *p, const void*k)
{
	
	return (*((Product**)p))->unit_price - (*((Product**)k))->unit_price;
}

int cmp_quantity(const void *p, const void*k)
{
	return ((*((Product**)p))->quantity - (*((Product**)k))->quantity);
}

int cmp_price(const void *p, const void*k)
{
	return ((*((Product**)p))->price - (*((Product**)k))->price);
}

//---------------------------------------------------------------------------
int cmp_rname(const void *p, const void*k)
{
	return strcmp((*((Product**)k))->name, (*((Product**)p))->name);
}

int cmp_runitPrice(const void *p, const void*k)
{

	return (*((Product**)k))->unit_price - (*((Product**)p))->unit_price;
}

int cmp_rquantity(const void *p, const void*k)
{
	return ((*((Product**)k))->quantity - (*((Product**)p))->quantity);
}

int cmp_rprice(const void *p, const void*k)
{
	return ((*((Product**)k))->price - (*((Product**)p))->price);
}

enum SORT
{
	NAME_SORT = 1,
	UNIT_PRICE_SORT,
	QUANTITY,
	PRICE
};

void Sort(List * plist, Product ** pArr)
{
	int sortHow = 0;
	int asc=-1;
	printf("어떤 순으로 정렬할지 선택하세요 \n");
	printf("1. 제품명 \n");
	printf("2. 단가 \n");
	printf("3. 개수 \n");
	printf("4. 금액 \n");

	while (sortHow < 1 || sortHow>4)
	{
		printf("선택 :");
		scanf("%d", &sortHow);
	}

	printf("오름차순 1 , 내림차순 : 0 \n");
	while (asc<0 || asc >1)
	{
		printf("선택 :");
		scanf("%d", &asc);
	}

	switch ((sortHow))
	{
	case NAME_SORT:
		if (asc)
		{
			qsort(pArr, plist->numberOfProduct, sizeof(Product*), cmp_name);
			break;
		}
		qsort(pArr, plist->numberOfProduct, sizeof(Product*), cmp_rname); break;
	case UNIT_PRICE_SORT: 
		if (asc)
		{
			qsort(pArr, plist->numberOfProduct, sizeof(Product*), cmp_unitPrice);
			break;
		}
		qsort(pArr, plist->numberOfProduct, sizeof(Product*), cmp_runitPrice); break;
	case QUANTITY: 
		if (asc)
		{
			qsort(pArr, plist->numberOfProduct, sizeof(Product*), cmp_quantity);
			break;
		}
		qsort(pArr, plist->numberOfProduct, sizeof(Product*), cmp_rquantity); break;
	case PRICE:
		if (asc)
		{
			qsort(pArr, plist->numberOfProduct, sizeof(Product*), cmp_price);
			break;
		}
		qsort(pArr, plist->numberOfProduct, sizeof(Product*), cmp_rprice); break;
	default:
		break;
	}

	arrayView(plist, pArr);
	
	addArrData(plist, pArr);
	
}

/*
 MENU
1. 매출현황 출력
2. 매출현황 내보내기
3. 상품 찾기
4. 상품 삭제
5. 매출현황 배열	//배열에 넣어서 저장 및 출력
6. 정렬
7. 종료
*/



int main(void)
{
	List list;
	Product * pArr[100];
	int choice;

	InitList(&list);
	ReadItem(&list);
	ReadSales(&list);
	PrintData(&list);
	arraySave(&list, pArr);
	choice = PrintMenu();

	while (choice != EXIT)
	{
		switch (choice)
		{
		case PRINT: PrintData(&list); break;
			//arrayView(&list, pArr); break;
		case FILEOUT: FileOut(&list); break;
		case FIND: Find(&list); break;
		case DELETE: DeleteProduct(&list); break;
		case ARRAY: arraySave(&list, pArr); break;
		case SORT: Sort(&list,pArr); break;
		case EXIT: break;
		default:
			break;
		}

		choice = PrintMenu();
	}
	

	return 0;
}