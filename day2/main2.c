#include <stdio.h>
#pragma warning(disable:4996)  // �������� �����ʰٴ�.

int get_num()
{
	return 40;
}

void main()
{
	int a[100];		//a[0] ~ a[99] �迭�� �ӵ� ���鿡�� �ſ� ����.

	// 1���� �迩�� ���ڿ� ó�� ����
	char arr[] = "abc";				// 4
	char brr[4] = "abc";			// 4
	char crr[] = { 'a','b','c' };	// 3
	char drr[4] = { 'a','b','c' };	// 4 �ʱ�ȭ ����Ʈ�� ������ ���ڸ��� ������ 0

	char err[2][10] = { "aaa","bbbb" };

	printf("%s \n", arr);
	printf("%s \n", brr);
	printf("%s \n", crr);
	printf("%s \n", drr);
	printf("%s \n", err[0]);
	printf("%s \n", err[1]);

	// a, b, d�� ���� ���·� ����. 


	//���� ������
	int n = 10; // ������ ���ϸ鼭 �ʱ�ȭ
	n = 20; // ���Կ����ڸ� �̿��� ����
	scanf_s("%d", &n);	// Ű���� �Է�(ǥ���Է�)�� ���� �Է�
	n = get_num();		// �Լ��� ���ϰ��� n�� ����
	*&n = 50;
	printf("%d %d \n", n, *&n);
 }