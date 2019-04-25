#include <iostream>
using namespace std;

class AAA
{
private:
	int a;
public:
	AAA() : a(0) {}
	AAA(int a) : a(a) {}
	void set_a(int data)
	{
		a = data;
	}
	int get_a(void) const
	{
		return a;
	}
};

class BBB : public AAA
{
private:
	int b;
public:
	BBB(int b) : AAA(),b(b){}
	BBB(const BBB &ref) : AAA(ref.get_a()) {}
	// 자식 클래스에서 대입연산자를 명시적으로 만들면 부모의
	// 디폴트 대입연산자를 명시적으로 호출해야한다.
	void operator=(const BBB& ref)
	{
		AAA::operator=(ref);	// 부모의 디폴트 대입 호출
		b = ref.b;
	}

	void set_b(int data)
	{
		b = data;
	}
	int get_b(void) const
	{
		return b;
	}
};

// 클래스 객체가 만들어질때 자동으로 생성되는 함수 4가지
// 생성자, 소멸자, 디폴트 복사, 디폴트 대입

int main(void)
{
	BBB ob1(20);		// 기본생성자
	BBB ob2(ob1);		// 디폴트 복사생성자
	BBB ob3 = ob1;		// 디폴트 복사생성자
	BBB ob4(40);
	ob4 = ob1;			// 디폴트 대입 연산자

	cout << ob1.get_b() << endl;
	cout << ob4.get_b() << endl;

	return 0;
}