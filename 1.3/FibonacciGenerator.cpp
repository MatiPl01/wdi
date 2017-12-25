#include "FibonacciGenerator.h"

FibonacciGenerator::FibonacciGenerator()
{
  f0 = 1;
  f1 = 1;
}

FibonacciGenerator::FibonacciGenerator(int a, int b)
{
  f0 = a;
  f1 = b;
}

int FibonacciGenerator::next()
{
  int tmp = f0 + f1;
  f0      = f1;
  f1      = tmp;
  return tmp;
}