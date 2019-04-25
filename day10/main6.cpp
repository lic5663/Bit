#include <iostream>
using namespace std;

struct shallow
{
	int key;
	const char *p;
};

struct deep
{
	int key;
	char p[10];
};

int main(void)
{
	char p[] = "AAA";
	shallow a = { 10, p }, b;

	shallow f = { 10, "AAA" };


	deep c = { 20,"CCC" }, d;

	cout << a.p << endl;
	b = a;
	cout << b.p << endl;

	d = c;

	return 0;
}