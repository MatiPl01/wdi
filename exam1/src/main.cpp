#include <cstdio>
#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

int main(void)
{
  int a = 1;
  int b = 2;

  int k;
  cin >> k;

  int diff_a   = abs(k - a);
  int diff_b   = abs(k - b);
  int diff_min = INT_MAX;
  int result;

  while(diff_min > diff_a || diff_min > diff_b)
  {
    diff_min = min(diff_a, diff_b);

    if(diff_a < diff_b)
    {
      diff_min = diff_a;
      result   = a;
    }
    else if(diff_a > diff_b)
    {
      diff_min = diff_b;
      result   = b;
    }
    else if(diff_a == diff_b)
    {
      diff_min = diff_b;
      result   = min(a, b);
    }

    b = b + a;
    a = a + b / 3;

    diff_a = abs(k - a);
    diff_b = abs(k - b);
  }

  cout << result << endl;

  return 0;
}