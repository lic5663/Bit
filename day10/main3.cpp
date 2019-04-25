#include <iostream>
#include <cstdlib>
using namespace std;

void func1(int *(&ppa))
{
	*ppa = 10;
}

void func2(int *ppa)
{
	*ppa = 20;
}


int main(void)
{
	int a = 10;
	int *pa = &a;
	func1(pa);
	cout << *pa << endl;
	func2(pa);
	cout << *pa << endl;
	return 0;
}