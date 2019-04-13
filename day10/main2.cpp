#include <iostream>
#include <cstdlib>
using namespace std;

struct Number
{
	int fst;
	int snd;
};

Number& NumberAdd(Number &ra, Number &rb)
{
	Number *psum = (Number*)malloc(sizeof(Number));
	psum->fst = ra.fst + rb.fst;
	psum->snd = ra.snd + rb.snd;

	return *psum;
}


int main(void)
{

	Number *pa = (Number*)malloc(sizeof(Number));
	Number *pb = (Number*)malloc(sizeof(Number));
	pa->fst = 1;
	pa->snd = 2;
	pb->fst = 10;
	pb->snd = 20;

	Number &rpa = NumberAdd(*pa, *pb);
	cout << rpa.fst << ' ' << rpa.snd << endl;

	free(pa);
	free(pb);
	free(&rpa);
	cout << rpa.fst << ' ' << rpa.snd << endl;

	const int a = 10;
	const int *p = &a;
	const int *(&rp) = p;

	cout << *p << ' ' << *rp << endl;


	return 0;
}