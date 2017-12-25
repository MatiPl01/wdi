#include <cstdio>
#include <iostream>
#include "fibonacciGenerator.h"

using namespace std;

int main(void)
{
  FibonacciGenerator generator;

  for(int i = 0; i < 10; i++)
  {
    printf("%d ", generator.next());
  }
  printf("\n");

  return 0;
}