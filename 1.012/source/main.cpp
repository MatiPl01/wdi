#include <iostream>

using namespace std;

/**
 * Dany jest ciąg określony wzorem: A(n+1) = (A(n)%2)\*(3\*A(n)+1)+(1-A(n)%2)\*A(n)/2 Startując z
 * dowolnej liczby naturalnej >1 ciąg ten osiąga wartość 1. Napisać program, który znajdzie wyraz
 * początkowy z przedziału 2-10000 dla którego wartość 1 jest osiągalna po największej liczbie
 * kroków.
 */

int next(int n)
{
  return (n % 2) * (3 * n + 1) + (1 - n % 2) * n / 2;
}

#ifndef TEST
int main(void)
{
  int result = 0;
  for(int i = 2; i <= 10000; i++)
  {
    int steps = 0;
    int n     = i;
    while(n != 1)
    {
      n = next(n);
      steps++;
    }
    if(steps > result)
      result = steps;
  }

  printf("%d\n", result);

  return 0;
}
#endif
