#include<iostream>
#include<cstdlib>
using namespace std; //using ���ù�
using std::cout;     //using ����

class bob {
public:
	void eat()
	{
		cout << "��Դ�" << endl;
	}
};

class kok {
public:
	void eat()
	{
		cout << "���Դ�" << endl;
	}
};

class kim {
public:
	void eat()
	{
		cout << "��Դ�" << endl;
	}
};
//main�Լ����� ��,��,���� ���ε��� �����ϰ� �԰� �ֽ��ϴ�.
//Wrap Ŭ������ ����� 
//main�Լ����� brunch��ü�� ����Ͽ� wrap ��ü�� ���
//��,��, ���� �ѹ��� �����ÿ�.
class Wrap 
{
private:
	bob b;
	kok g;
	kim k;

public:
	Wrap(bob bb, kok kk, kim km) {};

	void eat()
	{
		b.eat();
		g.eat();
		k.eat();	
	}
};

class Brunch {
public:
	void eattherice(bob &rb) { rb.eat(); }
	void eatthesoup(kok &rok) { rok.eat(); }
	void eatthekim(kim &rk) { rk.eat(); }
	void eatAll(Wrap &rp) { rp.eat(); }
};
int main()
{
	Brunch bb;
	bob ob;
	kok ok;
	kim im;
	Wrap wrap(ob, ok, im);

	bb.eattherice(ob);
	bb.eatthesoup(ok);
	bb.eatthekim(im);

	bb.eatAll(wrap);

}