#include "fibonacciGenerator.h"

FibonacciGenerator::FibonacciGenerator()
{
  element = -1;
  f0      = 1;
  f1      = 1;
}

FibonacciGenerator::FibonacciGenerator(int a, int b)
{
  element = -1;
  f0      = a;
  f1      = b;
}

int FibonacciGenerator::next()
{
  element++;
  if(element == 0)
    return 0;
  if(element == 1)
    return f0;
  if(element == 2)
    return f1;

  int tmp = f0 + f1;
  f0      = f1;
  f1      = tmp;
  return tmp;
}