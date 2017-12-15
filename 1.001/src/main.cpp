#include <iostream>

using namespace std;

int main(void)
{
	int f0 = 1;
	int f1 = 1;

	cout << 0 << " " << f0 << " " << f1 << " ";

	while(f0 + f1 < 1000000)
	{
		int tmp = f0 + f1;
		cout << tmp << " ";
		f0 = f1;
		f1 = tmp;
	}

	return 0;
}