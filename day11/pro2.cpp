#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

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

class matrix
{
private:
	int rows;
	int cols;
	int** mat;

public:
	matrix(int c, int r) : cols(c), rows(r)
	{
		mat = new int* [cols];
		
		for (int i = 0; i < cols; i++)
		{
			mat[i] = new int[rows];
		}
	}

	~matrix()
	{
		for (int i = 0; i < cols; i++)
		{
			delete[]mat[i];
		}
		delete[]mat;
	}
	
	int& elem(int col, int row) const
	{
		return mat[col][row];
	}

	int get_rows() const
	{
		return rows;
	}

	int get_cols() const
	{
		return cols;
	}

	void print() const
	{
		for (int i = 0; i < cols; i++)
		{
			for (int j = 0; j < rows; j++)
			{
				printf("%2d ", mat[i][j]);
			}
			cout << endl;
		}
	}

	void setRand()
	{
		srand(time(NULL));

		for (int i = 0; i < cols; i++)
		{
			for (int j = 0; j < rows; j++)
			{
				mat[i][j] = rand() % (rows * cols);
			}
		}
	}

	int maxpixel() const
	{
		int max = -1;
		for (int i = 0; i < cols; i++)
			for (int j = 0; j < rows; j++)
				if (max < mat[i][j])
					max = mat[i][j];
			
		return max;
	}


};

int main(void)
{
	matrix mx(3, 5);
	mx.setRand();
	mx.print();
	cout << "mx 최대값은 : " << mx.maxpixel() << endl;
	cout << "mx row : " << mx.get_rows() << endl;
	cout << "mx col : " << mx.get_cols() << endl;
	cout << "mx의 2,2 인덱스 값은" << mx.elem(2, 2) << endl;


	return 0;
}
