#include <cstdio>
#include <iostream>

#include "mymath.h"

using namespace std;

/**
 * Check if given number is prime number
 */

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