#include <cstdio>
#include "fibonacciGenerator.h"

int main(void)
{
	FibonacciGenerator generator;

	for(int i = 0; i < 10; i++)
	{
		printf("%d ", generator.next());
	}
	printf("\n");

	return 0;
}