#include <iostream>

/**
 * Napisz program wczytujący liczbę naturalną z klawiatury i odpowiadający na pytanie, czy liczba
 * zakończona jest unikalną cyfrą.
 */

using namespace std;

#ifndef TEST
int main()
{
  int x;
  cin >> x;

  bool digits[10] = {false};
  int  mask       = 10;
  int  last       = x % 10;

  while(mask <= x)
  {
    digits[(x / mask) % 10] = true;
    mask *= 10;
  }

  if(!digits[last])
    cout << "TAK" << endl;
  else
    cout << "NIE" << endl;

  return 0;
}
#endif