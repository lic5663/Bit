#include <iostream>
using namespace std;

class AAA
{
private:
	int num;
public:
	AAA(int n) : num(n){}
	virtual void view_num() const
	{
		cout << num << endl;
	}
	int get_num() const
	{
		return num;
	}
};

class BBB : public AAA
{
private:
	int num2;
public:
	BBB(int n1, int n2) : AAA(n1), num2(n2) {}
	void view_num() const
	{
		cout << get_num() << ", "<< num2 << endl;
	}
};

int main(void)
{
	AAA a(9);
	BBB b(7, 5);
	AAA* pa = new BBB(15, 41);
	AAA* paa = new AAA(19);

	b.view_num();
	a.view_num();
	pa->view_num();

	BBB* pb;
	pb = dynamic_cast<BBB*>(pa);
	pb->view_num();

	pb = dynamic_cast<BBB*>(paa);
	cout << "pb :" << pb << endl;
	pb->view_num();


	return 0;
}
