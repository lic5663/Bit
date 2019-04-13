#include <iostream>
using namespace std;

void swap1(int *pa, int *pb)
{
	int tmp;
	tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

// 원본 보니 콜 바이 레퍼런스임
void swap2(int &ra, int &rb)
{
	int tmp;
	tmp = ra;
	ra = rb;
	rb = tmp;
}

void swap3(int * &rpa, int * &rpb)
{
	int * tmp;
	tmp = rpa;
	rpa = rpb;
	rpb = tmp;
}


int main(void)
{
	int a = 10, b = 5;

	swap1(&a, &b);	// 콜 바이 레퍼런스
	cout << a << ' ' << b << endl;

	swap2(a, b);	// 이것만 보고는 알수없다. 원본 함수를 보고 콜 바이 밸류, 콜바이 레퍼런스를 판단한다.
	cout << a << ' ' << b << endl;

	int *pa = &a;
	int *pb = &b;

	swap3(pa, pb);
	cout << *pa << ' ' << *pb << endl;
	cout << a << ' ' << b << endl;

	return 0;
}