#include <cstdio>

int next(int n)
{
	return (n%2)*(3*n+1)+(1-n%2)*n/2;
}

int main(void)
{
	int result = 0;
	for(int i = 2; i <= 10000; i++)
	{
		int steps = 0;
		int n = i;
		while(n != 1)
		{
			n = next(n);
			steps++;
		}
		if(steps > result) result = steps;
	}

	printf("%d\n", result);

	return 0;
}