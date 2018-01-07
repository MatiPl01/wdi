#include <iostream>

using namespace std;

/**
 * Dana jest liczba naturalna o niepowtarzających się cyfrach pośród których nie ma zera. Ile
 * różnych liczb podzielnych np. przez 7 można otrzymać poprzez wykreślenie dowolnych cyfr w tej
 * liczbie. Np. dla 2315 będą to 21, 35, 231, 315.
 */

int search(int x, int mask)
{
  int result = 0;
  int right  = x % mask;
  int left   = x / (mask * 10);
  left *= mask;
  int new_x = left + right;

  if(new_x % 7 == 0 && new_x != 0)
    result++;

  if(mask < new_x)
    result += search(new_x, mask);
  if(mask * 10 < x)
    result += search(x, mask * 10);
  return result;
}

#ifndef TEST
int main()
{
  int x;
  cin >> x;
  cout << search(x, 1) << endl;
  return 0;
}
#endif