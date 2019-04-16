#include <iostream>
using namespace std;

template <typename T>

class MyTemplate
{
private:
	T data;
public:
	MyTemplate(T _data)
	{
		data = _data;
	}

	int Compare(T in)
	{
		return data - in;
	}

	operator T()
	{
		return data;
	}

};