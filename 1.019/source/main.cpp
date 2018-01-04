#include <iostream>

using namespace std;

/**
 * Napisać program obliczający wartości cos(x) z rozwinięcia w szereg Maclaurina.
 */

double cos(double x)
{
  const int N = 100;

  double cos       = 1;
  double numerator = 1;
  double factorial = 2;
  int    sign      = -1;

  for(int i = 1; i < N * 2; i += 2)
  {
    numerator *= x * x;
    cos += sign * (numerator) / factorial;
    factorial = factorial * (i + 2) * (i + 3);
    sign *= -1;
  }
  return cos;
}

#ifndef TEST
int main()
{
  double x;
  cin >> x;

  cout << cos(x) << endl;
  return 0;
}
#endif