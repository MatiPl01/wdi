#include <cstdio>
#include <iostream>

#include "myMath.h"

using namespace std;

/**
 * Check if given number is prime number
 */

#ifndef TEST
int main(void)
{
  int n;
  cin >> n;

  if(is_prime(n))
    cout << "TAK" << endl;
  else
    cout << "NIE" << endl;

  return 0;
}
#endif