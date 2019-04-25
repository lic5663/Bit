#include <iostream>
#include <string>
using namespace std;

//template <typename T>
//T add(T a, T b) {} // �Լ� ���ø�
//add<int>(10, 20); //���� ȣ��
//add(10, 20); //���� ȣ��
//int add<char>(char a, char b){} //�Լ� ���ø��� ���� ������� ���ø� �Լ�
// �μ��� T�� �Ƚᵵ ���� �߻�
//
//
//template<>char* add(char *a, char *b){} //����Ư��ȭ
//template<>char* add<>(char *a, char *b) {} //����Ư��ȭ
//template<>char* add<char*>(char *a, char *b) {} //����Ư��ȭ
////------------------------------------------------------------
//template <typename T> class point {} //Ŭ��
//template <typename T> class point { pubic: T add(T a, T b); } //Ŭ�۾��� ����Լ� ����
//template <typename T> T point<T>::add(T a, T b) {} //Ŭ�۾��� ����Լ� ����
//point<int> ob(3, 4);
//point<other*> ob(3, 4);	// T�� ��ü�� ���� �� �ִ�.
//point<other<int>*> ob(3, 4);  //�����Ѱ� typdef�� ����ȭ �Ѵ�. typedef other<int>* TTR;
//
//template <>class point<int>{};//Ŭ��Ư��ȭ (Ŭ���� ���ø��� <int>���� ��, ���� �߻�)
//template <>class point<int, char> {};//Ŭ��Ư��ȭ
//template <typename T> class point<T, char> {};//Ŭ�ۺκ�Ư��ȭ
//template <typename T, int size> class point{};//Ŭ�� ����
//template <typename T=int, int size=10> class point {};//Ŭ�� ����Ʈ����
//template <typename T, typename T>   T func2(T a, T b);  // ����, T�� �ߺ� ���� 
//template <typename T, typename U, typename V>   U func2(T a, V b);  // ����, U�� ���μ��� ������ ���� �׷��� ������ �߻�

// ��� Ÿ�Կ� ���� 2���� ���� ���ϴ� add �Լ� ���ø� ����
// string ���� ��� �Լ� ���ø� Ư��ȭ�� �����Ͻÿ� �� ���ڿ��� ���̽ÿ�.

template <typename T>
T add(T a, T b)
{
	return a + b;
}

template<>
string add(string a, string b)
{
	return a + b;
}




int main(void)
{
	int a = 5;
	int b = 7;
	int c = add(a, b);
	cout << c << endl;

	string s1 = "hello", s2 = "world";

	string str = add(s1,s2);
	cout << str << endl;

	string s3 = add<string>("hi", "ho");
	cout << s3 << endl;

	return 0;
}