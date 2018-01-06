#include <iostream>

using namespace std;

/**
 * Napisz program wczytujący liczbę naturalną z klawiatury i odpowiadający na pytanie, czy liczba ta
 * zawiera cyfrę równą liczbie swoich cyfr.
 */

#ifndef TEST
int main()
{
  int x;
  cin >> x;

  int  no_digits  = 0;
  bool digits[10] = {false};
  int  mask       = 1;

  while(mask <= x)
  {
    digits[(x / mask) % 10] = true;
    no_digits++;
    mask *= 10;
  }

  if(digits[no_digits])
    cout << "TAK" << endl;
  else
    cout << "NIE" << endl;

  return 0;
}
#endif