#include <stdio.h>

int passbook = 100;

int get_bank()
{
	return passbook;
}

void set_bank()
{
	passbook++;
}


int main(void)
{
	int withdraw;

	set_bank();

	withdraw = get_bank();

	printf("%d\n", withdraw);

	return 0;
}