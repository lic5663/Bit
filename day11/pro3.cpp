#include <iostream>
#include <cstdlib>
#include <string.h>
#include <time.h>
using namespace std;
#pragma warning (disable:4996)

class Engine
{
private:
	int horsepower;
	int get_hp() const
	{
		return horsepower;
	}
public:
	Engine(int hp = 120) : horsepower(hp) {}
	void view_HP() const
	{
		cout << "마력 : " << get_hp() << endl;
	}
	int get_get_hp() const
	{
		return get_hp();
	}
	
};

class intercoolerEngine : public Engine
{
private :
	char *cooler;
public:
	intercoolerEngine(int hp, const char* co = "물" ) :Engine(hp)
	{
		cooler = new char[strlen(co)+1];
		strcpy(cooler, co);
	}

	intercoolerEngine(const intercoolerEngine& source) : Engine(source.get_get_hp())
	{
		cooler = new char[strlen(source.cooler) +1 ];
		strcpy(cooler, source.cooler);
	}
	~intercoolerEngine()
	{
		delete[] cooler;
	}

	void view_cooler() const
	{
		view_HP();
		cout << "쿨러 : " << cooler << endl;
	}
};

class turboEngine : public intercoolerEngine
{
private :
	char turborcharger;
public:
	turboEngine(int hp, const char * co, char charger) : intercoolerEngine(hp, co)
	{
		turborcharger = charger;
	}
	void view_turbo() const
	{
		view_cooler();
		cout << "터보 : " << turborcharger << endl;
	}
};

int main(void)
{
	Engine eng1(150);
	eng1.view_HP();

	intercoolerEngine eng2(270,"물");
	eng2.view_cooler();
	intercoolerEngine eng3 = eng2;
	eng3.view_cooler();

	turboEngine eng4(290, "오일", 'B');
	eng4.view_turbo();

	return 0;
}

