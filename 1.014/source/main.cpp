#include <cstdio>
#include <iostream>

using namespace std;

/**
 * Napisać program wyznaczający pierwiastek kwadratowy ze wzoru Newtona
 */

float absolute(float a)
{
  return a < 0 ? -a : a;
}

#ifndef TEST
int main(void)
{
  float n;
  cin >> n;

  float a       = n / 2;
  float epsilon = 0.001;

  while(absolute((n / a) - a) > epsilon)
  {
    a = (a + (n / a)) / 2;
  }

  printf("%f\n", a);
  return 0;
}
#endif
