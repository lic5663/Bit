#include <iostream>
using namespace std;

class engine 
{
private:
	int km;
	char mode;
public:
	engine(int velocity = 0 , char mod = 'e') : km(velocity), mode(mod) {}	// 생성자
	void speed_engine(void) //모드와 속도 출력
	{
		cout << "mode : " << this->mode << " 속도 : " << this->km << endl;
	}
	void stop_engine(void)   //엔진정지 출력
	{
		cout << "엔진을 정지합니다" << endl;
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
	engine * history;    //enigne형태의 history
	int count;
public:
	void make_history_size() //실제 history로 넣어야 할 engine배열을 만든다.(20rㅐ)
	{
		this->history = new engine[20];
		this->count = 0;
	}

	void update_history(int rkm, const char *rmode) //사용자의 입력모드가 발생할때마다 history를 누적한다.
	{
		history[count].set_km(rkm);
		history[count].set_mode(*rmode);
		count++;
	}

	void display_history(void) //history내역을 출력해준다.
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
	black_box * eye; //차안에 블랙박스 기능을 넣을 수도 있고 뺄수 도 있다.
public:
	engine * sedan, *sports; //차의 옵션에 따라 에코모드로 출발 , 스포츠 모드 옵션인경우 스포츠모드 선택가능하겠다.

	car()
	{
		sedan = new engine(0, 'e');
		sports = new engine(0, 's');
	}

	void autoStop(void) //장애물을 보고 자동 정지한다 (출력)
	{
		if (sedan != NULL)
			sedan->stop_engine();
		
		if (sports != NULL)
			sports->stop_engine();
	}

	void make_bbox(void) //블박클래스를 만들고//블박내부에 engine형태의 history를 20개 만든다. 
	{
		this->eye = new black_box;
		this->eye->make_history_size();
	}


};

// e 연비 주행 s 과속주행  -> 둘다 다음은 속도 입력
// h 는 여태 어떤 모드에서 어느 속도로 달렸는지 출력.

int main(void)
{
	int km;
	char mode;
	bool repeat = true;

	car tico;
	tico.make_bbox();

	while (repeat)
	{
		cout << "모드를 선택해주세요 e(cho), s(ports) , (주행 기록 (h))";
		mode = getchar();
		switch (mode)
		{
		case 'e':
			cout << "속도를 입력해주세요 : ";
			cin >> km;
			tico.sedan->set_km(km);
			tico.sedan->set_mode(mode); 
			tico.eye->update_history(km, &mode);
			break;
		case 's':
			cout << "속도를 입력해주세요 : ";
			cin >> km;
			tico.sports->set_km(km);
			tico.sports->set_mode(mode);
			tico.eye->update_history(km, &mode);
			break;
		case 'h':
			tico.eye->display_history();
			break;
		case 'x':
			cout << " 긴급 정지 !!" << endl;
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