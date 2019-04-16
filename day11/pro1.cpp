#include <iostream>
using namespace std;
//class Car 형태를 만들려고 한다.
//다음과 같이 3개의 멤버 변수가 있다.
//power
//gas
//brake
//Car ob0;    //10 , 10, 10
//Car ob1(200)   //200, 10, 10
//Car ob2(200, 30)  //200, 30, 10
//Car ob3(200, 30 , 40) //200, 30, 40 
//되도록 생성자를 구현하시오

class Car
{
private:
	int power;
	int gas;
	int brake;

public:
	Car(int p=10,int g=10,int b=10):power(p),gas(g),brake(b){}

	void view(void) const
	{
		cout << power << ", " << gas << ", " << brake << endl;
	}
};

int main(void)
{
	Car ob0;
	Car ob1(200);
	Car ob2(200, 30);
	Car ob3(200, 30, 40);

	ob0.view();
	ob1.view();
	ob2.view();
	ob3.view();

	return 0;
}