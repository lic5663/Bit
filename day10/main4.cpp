#include <iostream>
#include <cstdlib>
using namespace std;

int & func1(int &ra)
{
	ra += 10;
	return ra;
}

int func2(int &ra)
{
	ra += 10;
	return ra;
}

int main(void)
{
	int a = 10;
	int &rb = func1(a);	// ���۷����� ���۷�����
	rb += 10;
	cout << a << endl;

	a = 10;
	int rc = func1(a);	// ���۷����� �Ϲݺ����� (�Լ��� ���� ����)
	cout << a << endl;

	a = 10;
	int rd = func2(a);	// ���� �Ϲ� ������ ����
	cout << rd << endl;

	a = 10;
	//int &re = func2(a);	// a =10 -> ra = 20; return 20; �׷��� ���۷��� ������ ������� ���� �� ����. �׷��Ƿ� ���� �߻�
							// ���� ���۷��� �� ����
	const int &re = func2(a);	// const�� ����ÿ��� ���۷����� ������� ���� �� �ִ�.
	cout << re << endl;

	return 0;
}