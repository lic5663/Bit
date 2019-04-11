#include <stdio.h>
typedef int(*myfp_t)(int, int);

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
int div(int a, int b) { return a / b; }

void printMenu(void *p[5][2])
{
	int i = 0;

	while (p[i][1])
	{
		printf("%d. %s \n",i+1 ,(char*)p[i][1]);
		i++;
	}
}

int cal(void *p[5][2], int n)
{
	//return ((myfp_t)p[n - 1][0])(10, 5);
	return ((int(*)(int, int))p[n - 1][0])(10, 5);
}

void Calcul()
{
	void *p[5][2];
	int n;

	p[0][0] = add;
	p[1][0] = sub;
	p[2][0] = mul;
	p[3][0] = div;
	p[4][0] = 0;

	p[0][1] = "ADDITION";
	p[1][1] = "SUBTRACTION";
	p[2][1] = "MULTIPLY";
	p[3][1] = "DIVIDE";
	p[4][1] = 0;

	printMenu(p);
	printf("번호를 선택하세요 : ");
	scanf_s("%d", &n);
	printf("결과는 : %d", cal(p,n));


}


int main(void)
{
	Calcul();
	

	return 0;
}