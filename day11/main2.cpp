#include <iostream>
using namespace std;



int main(void)
{
	int* p = new int;
	int* p1 = new int[4];

	// int* p2 = new int[4][2];	// cpp�� 1���������� �迭�� ���� �� �ִ�. ������ ������
	// �׷��� �̷��� �����
	int** p2 = new int* [3];
	p2[0] = new int[5];
	p2[1] = new int[5];
	p2[2] = new int[5];

	delete []p2[0];
	delete []p2[1];
	delete []p2[2];
	delete []p2;

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


	return 0;
}