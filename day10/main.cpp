#include <iostream>
using namespace std;

void swap1(int *pa, int *pb)
{
	int tmp;
	tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

// ���� ���� �� ���� ���۷�����
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

	swap1(&a, &b);	// �� ���� ���۷���
	cout << a << ' ' << b << endl;

	swap2(a, b);	// �̰͸� ����� �˼�����. ���� �Լ��� ���� �� ���� ���, �ݹ��� ���۷����� �Ǵ��Ѵ�.
	cout << a << ' ' << b << endl;

	int *pa = &a;
	int *pb = &b;

	swap3(pa, pb);
	cout << *pa << ' ' << *pb << endl;
	cout << a << ' ' << b << endl;

	return 0;
}