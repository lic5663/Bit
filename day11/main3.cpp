#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

class vector
{
	int count;
	int* vct;
public:
	vector(int count) : count(count) { vct = new int[count]; }	// 벡터클래스의 생성자
	// 벡터클래스의 크기를 동적으로 count 만큼 할당

	vector(const vector& source)	// const는 필수는 아니지만 써서 원본 훼손은 막는게 좋다
	{
		cout << "복사생성자가 간드아" << endl;

		this->count = source.count;
		this->vct = new int[source.count];

		for (size_t i = 0; i < source.count; i++)
		{
			this->vct[i] = source.vct[i];
		}
	}

	~vector()
	{
		cout << "소멸자가 간드아" << endl;
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
	vector vt(10); // 10개의 메모리를 가리키는 vt가 만들어진다,
	vt.randset_vector();
	vt.view_vector("vt");

	vector vt2 = vt;	// 디폴트 복사생성자가 자동 처리
	//vt2.randset_vector();
	vt2.view_vector("vt2");

	return 0;
}