#include <iostream>
using namespace std;

class A
{
public:
	virtual void hi() const
	{
		cout << "�ȳ�" << endl;
	}
};

class B : public A
{
public:
	void hi() const
	{
		cout << "�ȳ��ϼ���" << endl;
	}
};

class C : public B
{
public:
	void hi() const
	{
		cout << "������ �ݰ�����" << endl;
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
		cout << "���θ� �Ѵ�" << endl;
	}
};

class J : public I
{
public :
	void Nothing()
	{
		cout << "�ϰ͵� ����" << endl;
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