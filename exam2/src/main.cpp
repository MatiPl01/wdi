#include <cstdio>
#include <iostream>
#include <climits>
#include <cstdlib>

using namespace std;

int main(void)
{
	const int MAX = 1000;
	int tab[MAX];

	const int num_of_el = 10;
	int results[num_of_el] = {0};
	int smalest = 0;
	int smalest_index = 0;

	srand(time(NULL));

	for(int i = 0; i < MAX; i++)
		tab[i] = rand() % 1001;

	for(int i = 0; i < MAX; i++)
	{
		int number = tab[i];
		if(number > smalest)
		{
			results[smalest_index] = number;
		
			smalest = INT_MAX;
			for(int x = 0; x < num_of_el; x++)
			{
				if(results[x] < smalest)
				{
					smalest = results[x];
					smalest_index = x;
				}
			}
		}
	}

	int sum = 0;
	for(int x = 0; x < num_of_el; x++)
		sum += results[x];

	cout << sum << endl;

	return 0;
}