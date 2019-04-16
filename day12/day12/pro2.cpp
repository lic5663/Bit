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
		telArr[0] = new tel("����", 111);
		telArr[1] = new tel("���ؿ�", 666);
		telArr[2] = new tel("�պ���", 909);
		telArr[3] = new tel("�����", 222);
		telArr[4] = new tel("���α�", 808);
		telArr[5] = new tel("����", 789);
		telArr[6] = new tel("�����", 404);
		telArr[7] = new tel("�ڼ���", 303);
		telArr[8] = new tel("�ڼ���", 987);
		telArr[9] = new tel("�ŵ���", 333);
		telArr[10] = new tel("�̰��",202);
		telArr[11] = new tel("������", 555);
		telArr[12] = new tel("Ȳ����", 456);
		telArr[13] = new tel("������", 654);
		telArr[14] = new tel("��ȣ��", 777);
		telArr[15] = new tel("���϶�", 101);
		telArr[16] = new tel("�̽¿�", 999);
		telArr[17] = new tel("������", 123);
		telArr[18] = new tel("������", 321);
		telArr[19] = new tel("������", 707);
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
	cout << ph["����"] << endl;
	cout << ph["������"] << endl;
	return 0;

	return 0;
}