#include <iostream>
#include <cstring>

using namespace std;

/**
 * Liczba Smitha to taka, której suma cyfr jest równa sumie cyfr wszystkich liczb występujących w
 * jej rozkładzie na czynniki pierwsze. Na przykład: 85=5\*17, 8+5=5+1+7. Napisać program wypisujący
 * liczby Smitha mniejsze od 1000000.
 */

int calculate_sum_of_digits(int x)
{
	int result = 0;
	while(x > 0)
	{
		result += x % 10;
		x /= 10;
	}
	return result;
}

void search(long long score_a, long long score_b, int max, bool * primes, int min_prime)
{
  if(score_a < max && score_b < max)
  {
  	if(score_b == calculate_sum_of_digits(score_a))
  		cout << score_a << endl;
    for(int i = 2; i < max; i++)
    {
    	if(primes[i] == true && i >= min_prime)
    	{
    		int sum = calculate_sum_of_digits(i);
      	search(score_a * i, score_b + sum, max, primes, i);
    	}
    }
  }
}

bool * find_primes(int N)
{
	bool * primes = new bool[N];

	primes[0] = false;
	primes[1] = false;
	memset(primes, true, N * sizeof(bool));

	for(int i = 2; i < N; i++)
	{
		if(primes[i] == true)
		{
			for(int x = i*2; x < N; x += i)
			{
				primes[x] = false;
			}
		}
	}
	return primes;
}

#ifndef TEST
int main()
{
	const int N = 1000000;

  int a;
  cin >> a;

  bool * primes = find_primes(a);

  search(1, 0, a, primes, 1);
  cout << endl;

  delete primes;
  return 0;
}
#endif