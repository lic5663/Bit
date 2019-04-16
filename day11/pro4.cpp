#include <iostream>
using namespace std;

class person
{
private:
	string perName;
	int perAge;

public:
	person(){}
	person(string name, int age) : perName(name), perAge(age){}
	void set_name(string name)
	{
		perName = name;
	}
	void set_age(int age)
	{
		perAge = age;
	}
};

class subject
{
private:
	string subjName;
	int subjScore;

public:
	subject() {}
	subject(string subname, int subscore) : subjName(subname), subjScore(subscore) {}
	void set_sub(string subname, int subscore)
	{
		subjName = subname;
		subjScore = subscore;
	}
};

int student::id_Total = 0;

class student : public person
{
private:
	subject* p_sub;
	int id_Number;
	static int id_Total;
	float id_Average;

public:
	student(string name, int age) : person(name, age)
	{
		p_sub = new subject[3];
		p_sub[0].set_sub("����", 0);
		p_sub[1].set_sub("����", 0);
		p_sub[2].set_sub("����", 0);

		id_Number = id_Total++;
	}
	

};

class gradeHandler
{
private:
	string UVsityName;
	student** studentArr;
	int studentTop;
public:
	gradeHandler(string uvname, int studentNum)
	{
		UVsityName = uvname;
		studentArr = new student*[studentNum];
		studentTop = 0;
	}
	void addStudent(string name, int age)
	{
		studentArr[studentTop] = new student(name, age);
		studentTop++;
	}
	student* getStudent(int id)
	{
		return studentArr[id];
	}

};

enum CHOICE
{
	STUDENT_MANAGEMENT = 1,
	SCORE_MANAGEMENT,
	ADD_STUDENT = 1,
	STUDENT_MODIFICATION,
	STUDENT_DELETE
	
};

int main(void)
{
	string temp_s;
	int temp_i;
	int choice;
	int count = 0;
	cout << "�б���� �л����� �Է��Ͻÿ�" << endl;
	cout << "�б��� : ";
	cin >> temp_s;
	cout << "�л��� : ";
	cin >> temp_i;

	gradeHandler g_handler(temp_s, temp_i);

	while (true)
	{
		cout << "MAIN" << endl;
		cout << "1. �л�����" << endl;
		cout << "2. ��������" << endl;
		cout << "���� :: ";
		cin >> choice;

		switch (choice)
		{
		case STUDENT_MANAGEMENT:
			cout << " 1. �л��߰� 2. �л� ���� 3. �л� ����" << endl;
			cin >> choice;

			switch (choice)
			{
			case ADD_STUDENT : 
				cout << "�л��� : ";
				cin >> temp_s;
				cout << "��  �� : ";
				cin >> temp_i;
				g_handler.addStudent(temp_s, temp_i);
				break;

			case STUDENT_MODIFICATION :
				cout << "����� �̸��� �й��� �Է����ּ��� " << endl;
				cout << "�л��� : ";
				cin >> temp_s;
				cout << "��  �� : ";
				cin >> temp_i;

				student* modify_stu = g_handler.getStudent(temp_i);

				cout << "������ �̸��� ���̸� �Է����ּ���" << endl;
				cout << "�л��� : ";
				cin >> temp_s;
				cout << "��  �� : ";
				cin >> temp_i;

				modify_stu->set_name(temp_s);
				modify_stu->set_age(temp_i);

				break;

			case STUDENT_DELETE:
				cout << "����� �̸��� �й��� �Է����ּ��� " << endl;
				cout << "�л��� : ";
				cin >> temp_s;
				cout << "��  �� : ";
				cin >> temp_i;

			default:
				break;
			}
				

			switch ()
			{
			default:
				break;
			}



			

			

			
			
			

		default:
			break;
		}

	}


	return 0;
}