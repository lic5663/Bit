//Engine클래스는 마력(horsepower)을 표시한다.
//마력은 120에서 290마력을 값을 가질수 있다.
//가지고 있는 마력을 출력하는 const함수가 있다.
//해당 const함수에서는 마력에 직접적으로 접근할수 없는 상황이다.
//
//------------------------------------------ -
//
//intercoolerEngine클래스는 engine를 상속한다.
//내부적으로 cooler를 가지고 있다.
//cooler의종류는* 형태로 //"오일" 또는 "물" 형태가 입력된다.
//해당 마력과 쿨러를 출력하는 함수가 있다.
//intercoolerEngine클래스의 객체는 자신과 같은 객체를 그대로
//복사하는 능력이 있다.
//
//------------------------------------------ -
//
//turboEngine클래스는 intercoolerEngine클래스를 상속한다.
//내부적으로 turborchager를 가지고 있으며
//차저의 종류는 A, B, C type의 문자가 입력된다.
//
//--------------------------------------------
//
//1.engine클래스의 객체, 150마력에 해당하는eng1객체를 만들고 출력
//2. intercoolerEngine클래스 객체, 270마력에  "물"을 사용하는 eng2를
//만들고 출력
//3. intercoolerEngine eng3를 eng2로 부터 복사 후 eng3출력
//4. turboEngine클래스의 객체 eng4 는 290마력에 "오일" 그리고 차저는 'B'
//타입을 사용하는 객체이다.
//출력방법은 마력, 마력 + 오일, 마력 + 오일 + 차저 3가지형태로 출력된다.
//
//해당 객체에 소멸자에 필요하다면 delete 를 구현하시오



//person클래스는 private 형태의  이름과 나이를 갖는다.
//사람class person
//이름 perName
//나이 perAge
//
//과목 class subject
//전공명 subjName
//점수   subjScore
//
//
//학생 클래스는 person 클래를 상속받고  학번(const), 총점, 평균을 갖는다.
//과목명은 국어, 영어, 수학을 기본적으로 갖는다.과목클래스를 멤버로 갖는다.
//학생class student
//subject* p_sub
//학번 id_Number
//총점 id_Total
//평균 id_Average
//
//gradeHandler클래스에는 학교명과 학생클래스의 객체배열을 갖는다.
//이 때 객체배열의 수는 입력을 받는다.(학교마다 학생수가 다르므로)
//성적관리class gradeHandler
//학교명 UVsityName
//student 객체배열
//int studentTop
//
//
//실행 예)
//
//학교명과 학생수를 입력하시오.
//학교명:  어쩐대
//	학생수 : 10
//	MAIN
//	1. 학생관리
//	2. 성적관리
//	선택 ::
//
//	1. 학생관리
//	- 학생추가(자동으로학번이 증가한다.)
//	--학생명 : 무진정
//	-- 나   이 : 20
//	[4]으로 무진정(20) 학생이 추가됨
//	- 학생수정(학생명과 학번으로 허가 - 이름만 수정, 나이)
//	--학생명 : 무진정
//	-- 학   번 : 4
//	--학생명 : 무진장
//	-- 나   이 : 19
//	[4] 무진정(20)이 무진장(19)로 수정됨
//
//	- 학생삭제(학생명과 학번으로 허가 - 삭제시 학번에[*]이 표시되며 성적은 남는다)
//	2. 성적관리
//	- 재학생리스트를 출력해준다.(점수가 없다면 0으로 출력)
//	학번 이름(나이)    국어   영어   수학   총점  평균
//	[0]  안테나(22)      0       0      0       0       0
//	[1]  손낙지(32)      0       0      0       0       0
//	[2]  누군고(25)      0       0      0       0       0
//	[3]  고기판(27)      0       0      0       0       0
//	[4]  무진장(19)      0       0      0       0       0
//	- 성적추가
//	-- 학번입력 : 4   (학번입력시 없는 학생이면 MAIN화면으로 돌아가기)
//	* *무진장 학생 * *
//	--국어점수 : 70
//	--영어점수 : 80
//	--수학점수 : 90
//	[4]  무진장(19)      70     80     90      240     80