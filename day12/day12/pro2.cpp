#include <iostream>
#include <cstringt.h>
#pragma warning (disable:4996)
using namespace std;
#define MAX_SIZE 20

class tel
{
private:
	string name;
	int phoneNum;
public:
	tel(string _name, int _phone) : name(_name),phoneNum(_phone) {}
	string get_name()
	{
		return name;
	}
	int get_num()
	{
		return phoneNum;
	}
};

class telhandler
{
private:
	tel *telArr[MAX_SIZE];

public:
	telhandler()
	{
		telArr[0] = new tel("배상우", 111);
		telArr[1] = new tel("소준영", 666);
		telArr[2] = new tel("손병국", 909);
		telArr[3] = new tel("고승희", 222);
		telArr[4] = new tel("구민교", 808);
		telArr[5] = new tel("김기백", 789);
		telArr[6] = new tel("김다희", 404);
		telArr[7] = new tel("박선애", 303);
		telArr[8] = new tel("박성경", 987);
		telArr[9] = new tel("신동열", 333);
		telArr[10] = new tel("이경수",202);
		telArr[11] = new tel("조희은", 555);
		telArr[12] = new tel("황상진", 456);
		telArr[13] = new tel("강상헌", 654);
		telArr[14] = new tel("이호세", 777);
		telArr[15] = new tel("전하람", 101);
		telArr[16] = new tel("이승연", 999);
		telArr[17] = new tel("조민희", 123);
		telArr[18] = new tel("이인찬", 321);
		telArr[19] = new tel("지도현", 707);
	}

	int operator[](string name)
	{
		for (int i = 0; i < MAX_SIZE; i++)
		{
			if (telArr[i]->get_name() == name)
			{
				return telArr[i]->get_num();
			}
		}
		return -1;
	}


};

int main(void)
{
	telhandler ph;
	cout << ph["김기백"] << endl;
	cout << ph["이인찬"] << endl;
	return 0;

	return 0;
}