#include <iostream>
#pragma warning (disable:4996)
using namespace std;
#include <cstdio>

class Number
{
private:
	int fir;
	int sec;

public:
	Number(int first = 0, int second = 0) : fir(first), sec(second) {}

	void DisplayAndRead(const char * msg)
	{
		cout << msg;
		cin >> this->fir >> this->sec;
	}
	
	void printData(const char * msg)
	{
		cout << msg << ' ' << this->fir << " + " << this->sec << endl;
	}

	void addition(Number a, Number b)
	{
		this->fir = a.fir + b.fir;
		this->sec = a.sec + b.sec;
	}

};


int main()
{
	Number a, b, c;
	a.DisplayAndRead("A = ");
	b.DisplayAndRead("B = ");
	c.addition(a, b);
	a.printData(" A = ");
	b.printData(" B = ");
	c.printData(" A + B = ");

	return 0;
}