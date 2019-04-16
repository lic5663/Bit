#include <iostream>
using namespace std;

class AAA
{
private:
	int num;
public:
	AAA(int n):num(n){}

	void setAAA(int data)
	{
		num = data;
	}

	friend ostream& operator<<(ostream& os, AAA& a)
	{
		os << a.num;
		return os;
	}
};

class smart
{
	AAA* ptr;
public :
	smart(AAA* p) : ptr(p) {}
	~smart()
	{
		delete ptr;
	}

	AAA& operator*()	// ob.operator*()
	{
		return *ptr;
	}

	AAA* operator->()	// ob.operator->()
	{
		return ptr;
	}
};


int main(void)
{
	smart ob(new AAA(10));
	cout << *ob << endl;
	ob->setAAA(20);
	cout << *ob << endl;


	

	return 0;
}