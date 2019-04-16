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

	// temp ������
	String& operator= (const String& s)
	{
		this->len = s.len;

		if (s.str != NULL)
			delete[] str;

		this->str = new char[this->len +1 ];
		strcpy(this->str, s.str);

		return *this;
	}

	// strcat�� �޸� �Ҵ� ������ �� �о����
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

	// temp�� �Ҹ��� ��ȯ�Ǽ� ������ ����
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

// is�� �Է��� ���������� �ȹ��� s�� null�̶� �׷���.
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
		cout << "���� ���ڿ�!" << endl;
	else
		cout << "�������� ���� ���ڿ�!" << endl;

	String str4;
	cout << "���ڿ� �Է�: ";
	cin >> str4;
	cout << "�Է��� ���ڿ�: " << str4 << endl;
	return 0;
}