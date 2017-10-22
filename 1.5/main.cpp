#include <cstdio>
#include <iostream>

using namespace std;

/**
 * Finds integer sqrt of a number
 */

int main(void)
{
	int n;
	int sqrt = 0;
	int tmp = 1;
	int result = 0;
	cin >> n;

	while(sqrt <= n)
	{
		sqrt += tmp;
		tmp += 2;
		result++;
	} 

	cout << result-1 << endl;

	return 0;
}