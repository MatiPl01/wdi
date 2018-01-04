#include <cstdio>
#include <iostream>
#include "myMath.h"

using namespace std;

/**
  * Napisać program wyznaczający największy wspólny dzielnik 3 zadanych liczb.
  */

#ifndef TEST
int main(void)
{
  int a, b, c;
  cin >> a >> b >> c;

  printf("%d\n", nwd(nwd(a, b), c));

  return 0;
}
#endif