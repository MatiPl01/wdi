#include <iostream>

using namespace std;

/*
 * Napisać program wyliczający pierwiastek równania x^x=2017 metodą stycznych.
 */

int f(int x)
{
  return x * x - 2017;
}
int f_prim(int x)
{
  return 2 * x;
}

#ifndef TEST
int main()
{
  const int N = 100000000;
  const int a = 0;
  double    x = f(a);
  for(int i = 0; i < N; i++)
    x -= (double) f(x) / (double) f_prim(x);

  cout << x << endl;

  return 0;
}
#endif