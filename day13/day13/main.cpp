#include <iostream>
#include <string>
using namespace std;

//template <typename T>
//T add(T a, T b) {} // 함수 템플릿
//add<int>(10, 20); //템함 호출
//add(10, 20); //템함 호출
//int add<char>(char a, char b){} //함수 템플릿에 의해 만들어진 템플릿 함수
// 인수에 T를 안써도 에러 발생
//
//
//template<>char* add(char *a, char *b){} //함템특수화
//template<>char* add<>(char *a, char *b) {} //함템특수화
//template<>char* add<char*>(char *a, char *b) {} //함템특수화
////------------------------------------------------------------
//template <typename T> class point {} //클템
//template <typename T> class point { pubic: T add(T a, T b); } //클템안의 멤버함수 선언
//template <typename T> T point<T>::add(T a, T b) {} //클템안의 멤버함수 정의
//point<int> ob(3, 4);
//point<other*> ob(3, 4);	// T에 객체도 던질 수 있다.
//point<other<int>*> ob(3, 4);  //복잡한건 typdef로 간략화 한다. typedef other<int>* TTR;
//
//template <>class point<int>{};//클템특수화 (클래스 템플릿은 <int>생략 시, 문제 발생)
//template <>class point<int, char> {};//클템특수화
//template <typename T> class point<T, char> {};//클템부분특수화
//template <typename T, int size> class point{};//클템 인자
//template <typename T=int, int size=10> class point {};//클템 디폴트인자
//template <typename T, typename T>   T func2(T a, T b);  // 에러, T가 중복 선언 
//template <typename T, typename U, typename V>   U func2(T a, V b);  // 에러, U가 가인수로 사용되지 않음 그러면 에러가 발생

// 모든 타입에 대한 2개의 수를 더하는 add 함수 템플릿 구현
// string 형일 경우 함수 템플릿 특수화로 구현하시오 두 문자열을 붙이시오.

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