#include <cstdio>
#include <iostream>
#include "myMath.h"

using namespace std;

/**
 * Zmodyfikować wzór Newtona aby program z poprzedniego zadania obliczał pierwiastek stopnia 3.
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

  while(absolute((n / (a * a)) - a) > epsilon)
  {
    a = (a + (n / (a * a))) / 2;
  }

  printf("%f\n", a);
  return 0;
}
#endif