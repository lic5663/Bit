#include <iostream>
#include <cstringt.h>
#pragma warning (disable:4996)
using namespace std;

class weapon
{
private:
	char* wpName;

public:
	weapon(const char* wp_name)
	{
		wpName = new char[strlen(wp_name) + 1];
		strcpy(wpName, wp_name);
	}
	~weapon()
	{
		delete[] wpName;
	}
	char* get_wpName()
	{
		return wpName;
	}

};

class glove
{
private:
	char* gvName;
	weapon *wp;
public:
	glove(const char* gv_name, const char* wp_name)
	{
		wp = new weapon(wp_name);

		gvName = new char[strlen(gv_name) + 1];
		strcpy(gvName, gv_name);
	}
	~glove()
	{
		delete[] gvName;
	}
	weapon* get_wp()
	{
		return wp;
	}

};


class soldier
{
private:
	char* sdName;
	glove *gv;

public:
	soldier(const char* s_name, const char* gv_name, const char* wp_name)
	{
		gv = new glove(gv_name, wp_name);

		sdName = new char[strlen(s_name) + 1];
		strcpy(sdName, s_name);
	}
	~soldier()
	{
		delete[] sdName;
	}
	
	weapon* operator->()
	{
		return gv->get_wp();
	}


};



int main(void)
{
	soldier sd1("아이언맨", "철장갑", "초특급레이져");
	cout << sd1->get_wpName() << endl;

	return 0;
}