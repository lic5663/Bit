#include<iostream>
#include<cstdlib>
using namespace std; //using 지시문
using std::cout;     //using 선언

class bob {
public:
	void eat()
	{
		cout << "밥먹다" << endl;
	}
};

class kok {
public:
	void eat()
	{
		cout << "국먹다" << endl;
	}
};

class kim {
public:
	void eat()
	{
		cout << "김먹다" << endl;
	}
};
//main함수에서 밥,국,김을 따로따로 불편하게 먹고 있습니다.
//Wrap 클래스를 만들어 
//main함수에서 brunch객체를 사용하여 wrap 객체에 담긴
//밥,국, 김을 한번에 먹으시오.
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