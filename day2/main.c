#include <stdio.h>

void main()
{
	/*int a, b;
	a = 10;
	b = 6;

	printf(" a = %d, b = %d \n", a, b);

	a = a ^ b;
	printf(" a = %d \n", a);
	b = a ^ b;
	printf(" b = %d \n", b);
	a = a ^ b;
	printf(" a = %d \n", a);
	getchar();*/

	int a = 0xA; // 1010
	int sum;

	// bit set : | �ش� bit�� 1�� set
	//a = a | 4;	 // 1111 = E
	//a = a | (1 << 2) | (1<<16);
	a |= (1 << 16) + (1 << 2);
	//printf("%x \n", a);


	// bit check : & �ش� bit ���� Ȯ��
	if (a & (1<<16))
		puts("true \n");
	else
		puts("false \n");

	//bit mask : & ���� ���� �����͸� ����
	a = 0x12345678;
	// a�� ���� 45 �κ��� mask�ؼ� ����Ͻÿ�
	printf("%x \n", a);
	a = a & 0xFF000;
	printf("%8x \n", a);

	// bit clear : &~ �ش� bit�� 0���� 
	a = 0x12345678;
	a = a & ~16;
	printf("%x \n", a);
	a &= ~((1 << 21)+(1<<3));
	printf("%x \n", a);


	// goto ���� ����Ͽ� 1~10������ ���� ����Ͻÿ�
	a = 0;
	sum = 0;
RE:
	a++;
	sum += a;
	printf("%d ", a);
	if (a < 10)
		goto RE;
	printf("sum : %d \n\n", sum);


}