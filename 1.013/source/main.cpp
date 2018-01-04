#include <cstdio>
#include <iostream>
#include "fibonacciGenerator.h"

using namespace std;

/**
 * Napisać program wyznaczający wartość do której zmierza iloraz dwóch kolejnych wyrazów ciągu
 * Fibonacciego. Wyznaczyć ten iloraz dla różnych wartości początkowych wyrazów ciągu.
 */

#ifndef TEST
int main(void)
{
  FibonacciGenerator generator;
  int                prev;

  for(int i = 0; i < 40; i++)
  {
    int next = generator.next();
    printf("%f ", (float) next / (float) prev);
    prev = next;
  }
  printf("\n");

  return 0;
}
#endif