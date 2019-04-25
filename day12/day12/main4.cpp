#include <iostream>
using namespace std;

template <typename T, typename Q>
void nothing(T t, Q q)
{
	cout << "받은 데이터 " <<  t <<" 크기는 " << sizeof(T) << endl;
}

int main(void)
{
	//nothing(7);
	//nothing("tfef");
	nothing<int,char>(1,'c');
	nothing(1, 'c');
	//nothing<char>('t');
	//nothing<double>(6.2477);

	return 0;
}