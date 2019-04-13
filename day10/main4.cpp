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
	int &rb = func1(a);	// 레퍼런스를 레퍼런스로
	rb += 10;
	cout << a << endl;

	a = 10;
	int rc = func1(a);	// 레퍼런스를 일반변수로 (함수쪽 값이 복사)
	cout << a << endl;

	a = 10;
	int rd = func2(a);	// 값을 일반 변수로 받음
	cout << rd << endl;

	a = 10;
	//int &re = func2(a);	// a =10 -> ra = 20; return 20; 그러나 레퍼런스 변수는 상수값을 받을 수 없다. 그러므로 오류 발생
							// 값을 레퍼런스 로 받음
	const int &re = func2(a);	// const로 선언시에는 레퍼런스가 상수값을 받을 수 있다.
	cout << re << endl;

	return 0;
}