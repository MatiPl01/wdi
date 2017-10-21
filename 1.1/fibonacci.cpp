#include <cstdio>
#include <iostream>

using namespace std;

/**
 * Generates fibonacci number up to 1 000 000
 */

int main(void)
{
	int f0 = 1;
	int f1 = 1;

	cout << 0 << endl << f0 << endl << f1 << endl;

	while(f0 + f1 < 1000000)
	{
		int tmp = f0 + f1;
		cout << tmp << endl;
		f0 = f1;
		f1 = tmp;
	}

	return 0;
}