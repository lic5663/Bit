#include <stdio.h>
#include <stdlib.h>

typedef struct _engine
{
	int piston;
	int fan;
	int pipe;
}Engine;

typedef struct _car
{
	Engine * sedan, *sports;
}Car;

void Hyundai(Car * man)
{
	// 기존 상태
	//man->sedan->piston = 50;
	//man->sedan->fan = 30;
	//man->sedan->pipe = 20;

	// 체이닝 제거
	Engine *p = man->sedan;
	p->piston = 50;
	p->fan = 30;
	p->pipe = 20;
}

int main(void)
{
	Car hi;
	hi.sedan = (Engine *)malloc(sizeof(Engine));
	Hyundai(&hi);
	printf("%d %d %d \n", hi.sedan->piston, hi.sedan->fan, hi.sedan->pipe);

	return 0;
}