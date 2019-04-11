#include <stdio.h>
#include <Windows.h>

#define NDEBUG
#include <assert.h>
#pragma warning (disable:4996)

#define DEBUG
#ifdef DEBUG
#define _(exp) exp
#else
#define _(exp) (void*)0
#endif




main()
{
	//_(puts("test"));
	//getchar();

	int x;
	printf("\nEnter an integer value:");
	scanf("%d", &x);
	assert(x >= 0);
	printf("You entered %d", x);
	return(0);
}