#include <cstdio>
#include <iostream>

using namespace std;

/**
 * Znaleźć najmniejsze wyrazy początkowe zamiast 1,1 aby w ciągu analogicznym do ciągu
 * Fibonacciego wystąpił w nim wyraz równy numerowi bieżącego roku.
 */

struct pair_t
{
  int a;
  int b;
};

pair_t smallest_generators(int target)
{
  int result_a = 0, result_b = 0;
  int best = target;

  for(int a = 1; a < target / 2; a++)
  {
    for(int b = 1; b < target / 2; b++)
    {
      int f0 = a;
      int f1 = b;
      while(f0 + f1 < target + 2)
      {
        int tmp = f0 + f1;
        if(tmp == target)
        {
          if(a + b < best)
          {
            result_a = a;
            result_b = b;
            best     = a + b;
          }
        }
        f0 = f1;
        f1 = tmp;
      }
    }
  }
  pair_t pair;
  pair.a = result_a >= result_b ? result_b : result_a;
  pair.b = result_b < result_a ? result_a : result_b;
  return pair;
}

#ifndef TEST
int main(void)
{
  pair_t result = smallest_generators(2017);
  cout << result.a << " " << result.b << endl;

  return 0;
}
#endif