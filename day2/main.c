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

	// bit set : | 해당 bit를 1로 set
	//a = a | 4;	 // 1111 = E
	//a = a | (1 << 2) | (1<<16);
	a |= (1 << 16) + (1 << 2);
	//printf("%x \n", a);


	// bit check : & 해당 bit 상태 확인
	if (a & (1<<16))
		puts("true \n");
	else
		puts("false \n");

	//bit mask : & 일정 영역 데이터만 남김
	a = 0x12345678;
	// a가 가진 45 부분을 mask해서 출력하시오
	printf("%x \n", a);
	a = a & 0xFF000;
	printf("%8x \n", a);

	// bit clear : &~ 해당 bit만 0으로 
	a = 0x12345678;
	a = a & ~16;
	printf("%x \n", a);
	a &= ~((1 << 21)+(1<<3));
	printf("%x \n", a);


	// goto 문을 사용하여 1~10까지의 합을 출력하시오
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