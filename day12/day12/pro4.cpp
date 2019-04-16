#include <iostream>
#include <cstring>
using namespace std;
#pragma warning (disable:4996)

class String
{
private:
	int len;
	char* str;

public:
	String()
	{
		len = 0;
		str = NULL;
	}
	String(const char* s)
	{
		len = strlen(s);
		str = new char[len+1];
		strcpy(str, s);
	}
	String(const String& s)
	{
		len = s.len;
		str = new char[len+1];
		strcpy(str, s.str);
	}
	~String()
	{
		delete str;
	}

	// temp 증발함
	String& operator= (const String& s)
	{
		this->len = s.len;

		if (s.str != NULL)
			delete[] str;

		this->str = new char[this->len +1 ];
		strcpy(this->str, s.str);

		return *this;
	}

	// strcat은 메모리 할당 안해줌 걍 밀어넣음
	String& operator+= (const String& s)
	{
		len += s.len;
		char temp[100];
		strcpy(temp, str);

		delete(str);
		str = new char[len + 1];
		strcpy(str, temp);
		str = strcat(str, s.str);
		return *this;
	}

	bool operator== (const String& s)
	{
		int temp = strcmp(str, s.str);

		if (temp == 0)
			return true;
		else
			return false;
	}

	// temp때 소멸자 소환되서 맛간다 수정
	String operator+ (const String& s)
	{	
		char buffer[100];
		strcpy(buffer, str);
		strcat(buffer, s.str);

		return String(buffer);

	}

	friend ostream& operator<< (ostream& os, const String& s);
	friend istream& operator>> (istream& is, String& s);
};

ostream& operator<< (ostream& os, const String& s)
{
	os << s.str;
	return os;

}

// is가 입력을 정상적으로 안받음 s가 null이라 그렇다.
istream& operator>> (istream& is, String& s)
{
	char buff[100];
	is >> buff;

	s.len = strlen(buff);
	s.str = new char[s.len + 1];
	strcpy(s.str, buff);
	
	return is;
}


int main(void)
{
	String str1 = "I like ";
	String str2 = "string class";
	String str3 = str1 + str2;

	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;

	str1 += str2;
	if (str1 == str3)
		cout << "동일 문자열!" << endl;
	else
		cout << "동일하지 않은 문자열!" << endl;

	String str4;
	cout << "문자열 입력: ";
	cin >> str4;
	cout << "입력한 문자열: " << str4 << endl;
	return 0;
}