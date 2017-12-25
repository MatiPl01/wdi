#include <cstdio>
#include <iostream>
#include "fibonacciGenerator.h"

using namespace std;

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