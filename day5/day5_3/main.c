#include <stdio.h>
#include "left.h"
#include "right.h"

int main(void)
{
	int withdraw;

	set_bank();

	withdraw = get_bank();

	printf("%d\n", withdraw);

	return 0;
}