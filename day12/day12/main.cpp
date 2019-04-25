#include <iostream>
using namespace std;

class A
{
public:
	virtual void hi() const
	{
		cout << "안녕" << endl;
	}
};

class B : public A
{
public:
	void hi() const
	{
		cout << "안녕하세요" << endl;
	}
};

class C : public B
{
public:
	void hi() const
	{
		cout << "만나서 반가워요" << endl;
	}
};

class I
{
public:
	virtual void Study() = 0;
};

class L : public I
{
public:
	void Study()
	{
		cout << "공부를 한다" << endl;
	}
};

class J : public I
{
public :
	void Nothing()
	{
		cout << "암것도 안해" << endl;
	}
};


int main(void)
{
	A *a = new C;
	a->hi();

	A a;
	B *b;
	b = dynamic_cast<B*>(a);

	I* i = new L;
	i->Study();
	
	//J j;


	return 0;
}