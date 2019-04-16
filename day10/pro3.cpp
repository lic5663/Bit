#include <iostream>
using namespace std;

class engine 
{
private:
	int km;
	char mode;
public:
	engine(int velocity = 0 , char mod = 'e') : km(velocity), mode(mod) {}	// ������
	void speed_engine(void) //���� �ӵ� ���
	{
		cout << "mode : " << this->mode << " �ӵ� : " << this->km << endl;
	}
	void stop_engine(void)   //�������� ���
	{
		cout << "������ �����մϴ�" << endl;
		set_km(0);
	}


	// access function
	void set_km(int rkm) { this->km = rkm; }
	void set_mode(char rmode) { this->mode = rmode; }
	int get_km(void) { return this->km; }
	char get_mode(void) { return this->mode; }
};


class black_box {
private:
	engine * history;    //enigne������ history
	int count;
public:
	void make_history_size() //���� history�� �־�� �� engine�迭�� �����.(20r��)
	{
		this->history = new engine[20];
		this->count = 0;
	}

	void update_history(int rkm, const char *rmode) //������� �Է¸�尡 �߻��Ҷ����� history�� �����Ѵ�.
	{
		history[count].set_km(rkm);
		history[count].set_mode(*rmode);
		count++;
	}

	void display_history(void) //history������ ������ش�.
	{
		for (size_t i = 0; i < count; i++)
		{
			cout << i << ". ";
			history[i].speed_engine();
		}
	}
};



class car {
public:
	black_box * eye; //���ȿ� ���ڽ� ����� ���� ���� �ְ� ���� �� �ִ�.
public:
	engine * sedan, *sports; //���� �ɼǿ� ���� ���ڸ��� ��� , ������ ��� �ɼ��ΰ�� ��������� ���ð����ϰڴ�.

	car()
	{
		sedan = new engine(0, 'e');
		sports = new engine(0, 's');
	}

	void autoStop(void) //��ֹ��� ���� �ڵ� �����Ѵ� (���)
	{
		if (sedan != NULL)
			sedan->stop_engine();
		
		if (sports != NULL)
			sports->stop_engine();
	}

	void make_bbox(void) //���Ŭ������ �����//��ڳ��ο� engine������ history�� 20�� �����. 
	{
		this->eye = new black_box;
		this->eye->make_history_size();
	}


};

// e ���� ���� s ��������  -> �Ѵ� ������ �ӵ� �Է�
// h �� ���� � ��忡�� ��� �ӵ��� �޷ȴ��� ���.

int main(void)
{
	int km;
	char mode;
	bool repeat = true;

	car tico;
	tico.make_bbox();

	while (repeat)
	{
		cout << "��带 �������ּ��� e(cho), s(ports) , (���� ��� (h))";
		mode = getchar();
		switch (mode)
		{
		case 'e':
			cout << "�ӵ��� �Է����ּ��� : ";
			cin >> km;
			tico.sedan->set_km(km);
			tico.sedan->set_mode(mode); 
			tico.eye->update_history(km, &mode);
			break;
		case 's':
			cout << "�ӵ��� �Է����ּ��� : ";
			cin >> km;
			tico.sports->set_km(km);
			tico.sports->set_mode(mode);
			tico.eye->update_history(km, &mode);
			break;
		case 'h':
			tico.eye->display_history();
			break;
		case 'x':
			cout << " ��� ���� !!" << endl;
			tico.autoStop();
			break;
		case EOF:
			repeat = false;
			break;
		default:
			break;
		}
		if (mode != EOF)
			getchar();
	}


	return 0;
}