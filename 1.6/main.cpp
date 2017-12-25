#include <cstdio>
#include <iostream>

using namespace std;

/**
 * Finds aliquots of a number
 */

int main(void)
{
  int n;
  cin >> n;
  for(int tmp = 1; tmp <= n; tmp++)
    if(n % tmp == 0)
      cout << tmp << " ";
  return 0;
}