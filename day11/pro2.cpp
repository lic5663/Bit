#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

// ���ϴ� ũ���� matrix�� ����� Ŭ���� �����
// Ŭ������ : matrix
// rows : int // ����� private
// cols : int // ������
// mat : int **
//------------------------
// matrix(int , int) // public
//~matrix()
//elem(int,int) : int& // matrix ��� �̾Ƴ���
// Rows() : int  // ����� ����
// Cols() : int  // ������ ����
// print() // matrix ���
// setRand() // rand()�Լ��� �̿��� �� ä���
// maxpixel() : int //matrix ���� �� �� ���� ū ���� ã�� ����

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
	cout << "mx �ִ밪�� : " << mx.maxpixel() << endl;
	cout << "mx row : " << mx.get_rows() << endl;
	cout << "mx col : " << mx.get_cols() << endl;
	cout << "mx�� 2,2 �ε��� ����" << mx.elem(2, 2) << endl;


	return 0;
}
