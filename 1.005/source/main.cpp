#include <cstdio>
#include <iostream>

using namespace std;

/**
 * Napisać program obliczający pierwiastek całkowitoliczbowy z liczby naturalnej
 * korzystając z zależności 1+3+5+... = n^2.
 */

int sqrt(int n)
{
  int sqrt   = 0;
  int tmp    = 1;
  int result = 0;

  while(sqrt <= n)
  {
    sqrt += tmp;
    tmp += 2;
    result++;
  }

  return result - 1;
}

#ifndef TEST
int main(void)
{
  int n;
  cin >> n;
  cout << sqrt(n) << endl;
  return 0;
}
#endif