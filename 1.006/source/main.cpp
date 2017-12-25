#include <cstdio>
#include <iostream>

using namespace std;

/**
 * Finds aliquots of a number.
 * Napisać program wypisujący podzielniki liczby.
 */

#ifndef TEST
int main(void)
{
  int n;
  cin >> n;
  for(int tmp = 1; tmp <= n / 2; tmp++)
  {
    if(n % tmp == 0)
    {
      cout << tmp << " ";
    }
  }
  cout << n << endl;
  return 0;
}
#endif