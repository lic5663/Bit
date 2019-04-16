#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

class vector
{
	int count;
	int* vct;
public:
	vector(int count) : count(count) { vct = new int[count]; }	// ����Ŭ������ ������
	// ����Ŭ������ ũ�⸦ �������� count ��ŭ �Ҵ�

	vector(const vector& source)	// const�� �ʼ��� �ƴ����� �Ἥ ���� �Ѽ��� ���°� ����
	{
		cout << "��������ڰ� �����" << endl;

		this->count = source.count;
		this->vct = new int[source.count];

		for (size_t i = 0; i < source.count; i++)
		{
			this->vct[i] = source.vct[i];
		}
	}

	~vector()
	{
		cout << "�Ҹ��ڰ� �����" << endl;
		delete[] vct;
	}

	
	void randset_vector()
	{
		for (size_t i = 0; i < count; i++)
		{
			vct[i] = rand() % 100;
		}
	}

	void view_vector(const char *vw)
	{
		cout << vw << " = < ";
		for (size_t i = 0; i < count; i++)
		{
			cout << vct[i] << ' ';
		}
		cout << "> " << endl;
	}

	
};


int main(void)
{
	srand((unsigned)time(NULL));
	vector vt(10); // 10���� �޸𸮸� ����Ű�� vt�� ���������,
	vt.randset_vector();
	vt.view_vector("vt");

	vector vt2 = vt;	// ����Ʈ ��������ڰ� �ڵ� ó��
	//vt2.randset_vector();
	vt2.view_vector("vt2");

	return 0;
}