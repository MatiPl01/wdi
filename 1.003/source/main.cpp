#include <cstdio>
#include <iostream>

#include "fibonacciGenerator.h"

using namespace std;

/**
 * Napisać program sprawdzający czy istnieje spójny podciąg ciągu Fibonacciego o zadanej
 * sumie.
 */

#ifndef TEST
int main(void)
{
  int n;
  cin >> n;

  FibonacciGenerator * end_gen = new FibonacciGenerator();

  int end     = 0;
  int beg     = 0;
  int end_sum = 0;
  int beg_sum = 0;

  while(end < n)
  {
    end = end_gen->next();
    end_sum += end;

    beg_sum                      = 0;
    FibonacciGenerator * beg_gen = new FibonacciGenerator();
    while(beg < end)
    {
      if(end_sum - beg_sum == n)
      {
        cout << "TAK" << endl;
        return 0;
      }

      beg = beg_gen->next();
      beg_sum += beg;
    }

    delete beg_gen;
  }

  delete end_gen;

  cout << "NIE" << endl;
  return 0;
}
#endif