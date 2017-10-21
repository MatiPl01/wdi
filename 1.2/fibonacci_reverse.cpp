#include <cstdio>
#include <iostream>

using namespace std;

/**
 * Find smallest two numbers which used as fibonacci first initializers will generate 2017
 */

int main(void)
{
	int target = 2017;

	int result_a = 0, result_b = 0;
	int best = target;

	for(int a = 1; a < target/2; a++)
	{
		for(int b = 1; b < target/2; b++)
		{
			int f0 = a;
			int f1 = b;
			while(f0 + f1 < target+2)
			{
				int tmp = f0 + f1;
				if(tmp == target)
				{	
					if(a + b < best)
					{
						result_a = a;
						result_b = b;
						best = a + b;
					}
				}
				f0 = f1;
				f1 = tmp;
			}

		}
	}

	cout << result_a << " " << result_b << endl;

	return 0;
}