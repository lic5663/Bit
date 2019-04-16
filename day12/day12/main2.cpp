#include <iostream>
using namespace std;

class Number
{
private:
	int fir;
	int sec;
public:
	Number(int f, int s): fir(f), sec(s) {}
	void setNumber_fir(int data)
	{
		fir = data;
	}
	void setNumber_sec(int data)
	{
		sec = data;
	}
	int getNumber_fir(void) const
	{
		return fir;
	}
	int getNumber_sec(void) const
	{
		return sec;
	}

	// 멤버함수 a.operator==(b) , a == b 형태로 호출 가능
	bool operator==(const Number& n)
	{
		if (fir == n.getNumber_fir() && sec == n.getNumber_sec())
			return true;
		else
			return false;
	}

	Number operator+(int n)
	{
		fir += n;
		sec += n;

		return *this;
	}

	void view()const
	{
		cout << fir << ", " << sec << endl;
	}

	friend Number operator+(int n, Number& num);
	//friend bool operator==(const Number& n1, const Number& n2);


};

//// 깡 전역
//bool operator==(const Number &n1, const Number &n2)
//{
//	if (n1.getNumber_fir() == n2.getNumber_fir() && n1.getNumber_sec() == n2.getNumber_sec())
//		return true;
//	else
//		return false;
//}


//// friend로 해줄때
//bool operator==(const Number &n1, const Number &n2)
//{
//	if (n1.fir == n2.fir && n1.sec == n2.sec)
//		return true;
//	else
//		return false;
//}

//Number operator+(int n, Number& num)
//{
//	num.fir += n;
//	num.sec += n;
//	return num;
//}

Number operator+(int n, Number& num)
{
	return Number(num.fir + n, num.sec + n);
}


int main(void)
{
	Number a(10, 20);
	Number b(20, 30);

	a.view();
	a = a + 5;
	a.view();
	a = 5 + a;
	a.view();


	if (a == b)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	return 0;
}