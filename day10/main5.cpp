#include <iostream>
using namespace std;

class Number
{
private:
	int fst;
public:
	int snd;

	Number(){}			// ����Ʈ ������
	Number(int rfst)	// ���� ���� ������ : ������ �����ε�
	{
		fst = rfst;
	}

	void view(void)
	{
		cout << fst << endl;
	}
};

int main(void)
{
	Number oba;
	Number obb(10);
	Number *obc = new Number(10);

	oba.view();
	obb.view();
	obc->view();

	obb.snd = 30;
	cout << obb.snd << endl;
	

	return 0;
}