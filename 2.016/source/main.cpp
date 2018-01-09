#include <iostream>
#include <cstring>

using namespace std;

/**
 * Napisać program sprawdzający czy liczba jest liczbą Carmichaela.
 */

long long pow(int a, int b)
{
  long long result = 1;
  for(int i = 0; i < b; i++)
    result *= a;
  return result;
}

int nwd(int a, int b)
{
  while(a != b)
  {
    if(a > b)
      a -= b;
    if(b > a)
      b -= a;
  }
  return a;
}

bool is_carmichaels(int n, bool * primes)
{
  bool result = true;
  for(int i = 1; i <= n; i++)
    if(nwd(i, n) == 1)
    {
      cout << pow(i, n - 1) << " ";
      result &= (pow(i, n - 1) - 1) % n == 0;
    }
  cout << !primes[n] << " " << result << endl;
  return !primes[n] && result;
}

/*bool is_carmichaels(int n, bool * primes)
{
  int M = 0;
  int m = 1;
  while(M <= n)
  {
    int a = (6 * m) + 1;
    int b = (12 * m) + 1;
    int c = (18 * m) + 1;
    if(primes[a] && primes[b] && primes[c])
    {
      M = a*b*c;
      cout << M << " ";
      if(M == n)
        return true;
    }
    m++;
  }
  return false;
}*/

bool * find_primes(int N)
{
  bool * primes = new bool[N];

  primes[0] = false;
  primes[1] = false;
  memset(primes, true, N * sizeof(bool));

  for(int i = 2; i < N; i++)
    if(primes[i] == true)
      for(int x   = i * 2; x < N; x += i)
        primes[x] = false;

  return primes;
}

#ifndef TEST
int main()
{
  int a;
  cin >> a;

  bool * primes = find_primes(a);

  if(is_carmichaels(a, primes))
    cout << "TAK" << endl;
  else
    cout << "NIE" << endl;

  delete primes;
  return 0;
}
#endif