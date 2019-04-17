#include <iostream>
#include <string>
#include <cstring>
using namespace std;

template <typename T>
class Point
{
private:
	T fir;
	T sec;

public:
	Point(T f, T s) : fir(f),sec(s){}
	void max(void)
	{
		if (fir > sec)
			cout << fir << endl;
		else
			cout << sec << endl;
	}
};

template<>
class Point <char*>
{
private:
	const char* fir;
	const char* sec;
public:
	Point(const char * f, const char *s):fir(f),sec(s){}
	void max(void)
	{
		if (strcmp(fir, sec) > 0)
			cout << fir << endl;
		else
			cout << sec << endl;
	}
};

int main(void)
{
	Point<int> ob(1, 2);
	ob.max();

	Point<char*> ob2("abc", "BBB");
	ob2.max();

	return 0;
}