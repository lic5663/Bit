#include <iostream>
using namespace std;

namespace mystd
{
	int a = 10;
	namespace mydtdin
	{
		int a = 20;
	}
}

int a = 30; // ��������

class Num
{
private:
	int aaa;
	static int praaa;
public:
	int a;	// �� ���� ����ʵ�(static�� �����Ѵٸ� ������)
	static int ubaaa;

	Num(int a):a(a){}
	void set_aaa(int aaa)
	{
		this->aaa = aaa;
	}
	int get_aaa(void) const	// ��������� �������� �ʰڴ�.
	{
		return aaa;
	}
	static int get_private_aaa(void)
	{
		return praaa;
	}
};

int Num::praaa = 200;
int Num::ubaaa = 0;

int main(void)
{
	namespace myin = mystd::mydtdin;
	int a = 70;	// ��������
	Num ob(40);

	cout << mystd::a << endl;
	cout << mystd::mydtdin::a << endl;	// :: ��������(�ؼ�)������
	cout << ::a << endl;
	cout << ob.a << endl;
	cout << myin::a << endl;
	ob.set_aaa(50);
	cout << ob.get_aaa() << endl;
	cout << Num::ubaaa << endl;
	cout << Num::get_private_aaa() << endl;
	cout << a << endl;

	return 0;
}