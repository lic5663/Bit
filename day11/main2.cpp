#include <iostream>
using namespace std;



int main(void)
{
	int* p = new int;
	int* p1 = new int[4];

	// int* p2 = new int[4][2];	// cpp는 1차원형태의 배열만 만들 수 있다. 옆에거 오류뜸
	// 그래서 이렇게 만든다
	int** p2 = new int* [3];
	p2[0] = new int[5];
	p2[1] = new int[5];
	p2[2] = new int[5];

	delete []p2[0];
	delete []p2[1];
	delete []p2[2];
	delete []p2;

	// 원하는 크기의 matrix를 만드는 클래스 만들기
	// 클래스명 : matrix
	// rows : int // 행길이 private
	// cols : int // 열길이
	// mat : int **
	//------------------------
	// matrix(int , int) // public
	//~matrix()
	//elem(int,int) : int& // matrix 요소 뽑아내기
	// Rows() : int  // 행길이 리턴
	// Cols() : int  // 열길이 리턴
	// print() // matrix 출력
	// setRand() // rand()함수를 이용해 값 채우기
	// maxpixel() : int //matrix 내부 값 중 가장 큰 값을 찾아 리턴


	return 0;
}