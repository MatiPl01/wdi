#include <cstdio>
#include <iostream>

using namespace std;

int main(void)
{
	int k;
	cin >> k;

	k += 2;

	int a1 = 1;
	int a2 = 1;
	int a3 = a1 + a2;

	int b1 = 1;
	int b2 = 1;
	int b3 = 1;

	int c;
	c = 2;
	int result;
	while(true)
	{
		if(a3 < b3)
		{
			c++;
			result = a3;

			int tmp = a3;
			a3 = a3 + a2;
			a2 = tmp;

			if(c == k)
			{
				cout << result;
				break;
			}
		}
		else if(a3 > b3)
		{
			c++;
			result = b3;

			int tmp = b3;
			b3 = b3 + b2 + b1;
			b1 = b2;
			b2 = tmp;

			if(c == k)
			{
				cout << result;
				break;
			}
		}
		else if(a3 == b3)
		{
			c++;
			result = b3;

			int tmp = a3;
			a3 = a3 + a2;
			a2 = tmp;

			tmp = b3;
			b3 = b3 + b2 + b1;
			b1 = b2;
			b2 = tmp;

			if(c == k)
			{
				cout << result;
				break;
			}
		}
	}
	return 0;
}