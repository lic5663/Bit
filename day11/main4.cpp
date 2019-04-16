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
	// �ڽ� Ŭ�������� ���Կ����ڸ� ��������� ����� �θ���
	// ����Ʈ ���Կ����ڸ� ��������� ȣ���ؾ��Ѵ�.
	void operator=(const BBB& ref)
	{
		AAA::operator=(ref);	// �θ��� ����Ʈ ���� ȣ��
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

// Ŭ���� ��ü�� ��������� �ڵ����� �����Ǵ� �Լ� 4����
// ������, �Ҹ���, ����Ʈ ����, ����Ʈ ����

int main(void)
{
	BBB ob1(20);		// �⺻������
	BBB ob2(ob1);		// ����Ʈ ���������
	BBB ob3 = ob1;		// ����Ʈ ���������
	BBB ob4(40);
	ob4 = ob1;			// ����Ʈ ���� ������

	cout << ob1.get_b() << endl;
	cout << ob4.get_b() << endl;

	return 0;
}