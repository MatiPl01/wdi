#include <iostream>
#include <cmath>

using namespace std;

/**
 * Napisać program znajdujący wszystkie liczby N-cyfrowe dla których suma N-tych potęg cyfr liczby
 * jest równa tej liczbie, np. 153=1^3+5^3+3^3.
 */

void search(int a, int score_a, int score_b, int mask, int level)
{
  if(level > a)
  {
    if(score_b == score_a && score_a >= 100)
    {
      cout << score_b << " ";
    }
  }
  else
  {
    for(int i = 0; i < 10; i++)
    {
      search(a, score_a + (i * mask), score_b + pow(i, a), mask * 10, level + 1);
    }
  }
}

#ifndef TEST
int main()
{
  int a;
  cin >> a;

  search(a, 0, 0, 1, 1);
  cout << endl;

  return 0;
}
#endif