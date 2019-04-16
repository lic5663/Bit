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
		p_sub[0].set_sub("국어", 0);
		p_sub[1].set_sub("영어", 0);
		p_sub[2].set_sub("수학", 0);

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
	cout << "학교명과 학생수를 입력하시오" << endl;
	cout << "학교명 : ";
	cin >> temp_s;
	cout << "학생수 : ";
	cin >> temp_i;

	gradeHandler g_handler(temp_s, temp_i);

	while (true)
	{
		cout << "MAIN" << endl;
		cout << "1. 학생관리" << endl;
		cout << "2. 성적관리" << endl;
		cout << "선택 :: ";
		cin >> choice;

		switch (choice)
		{
		case STUDENT_MANAGEMENT:
			cout << " 1. 학생추가 2. 학생 수정 3. 학생 삭제" << endl;
			cin >> choice;

			switch (choice)
			{
			case ADD_STUDENT : 
				cout << "학생명 : ";
				cin >> temp_s;
				cout << "나  이 : ";
				cin >> temp_i;
				g_handler.addStudent(temp_s, temp_i);
				break;

			case STUDENT_MODIFICATION :
				cout << "대상의 이름과 학번을 입력해주세요 " << endl;
				cout << "학생명 : ";
				cin >> temp_s;
				cout << "학  번 : ";
				cin >> temp_i;

				student* modify_stu = g_handler.getStudent(temp_i);

				cout << "수정할 이름과 나이를 입력해주세요" << endl;
				cout << "학생명 : ";
				cin >> temp_s;
				cout << "나  이 : ";
				cin >> temp_i;

				modify_stu->set_name(temp_s);
				modify_stu->set_age(temp_i);

				break;

			case STUDENT_DELETE:
				cout << "대상의 이름과 학번을 입력해주세요 " << endl;
				cout << "학생명 : ";
				cin >> temp_s;
				cout << "학  번 : ";
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