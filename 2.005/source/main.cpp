#include <iostream>
#include "math.h"

using namespace std;

/**
 * Napisz program wczytujący liczbę naturalną z klawiatury i odpowiadający na pytanie, czy jej cyfry
 * stanowią ciąg rosnący.
 */

int get_digit(long source, int index)
{
  return (source / (int) pow(10, index)) % 10;
}

#ifndef TEST
int main()
{
  int x;
  cin >> x;

  int  index  = 0;
  int  last   = get_digit(x, index++);
  bool result = true;

  while(result && pow(10, index) <= x)
  {
    int curr = get_digit(x, index++);
    if(curr <= last)
      result = false;

    last = curr;
  }

  if(result)
    cout << "TAK" << endl;
  else
    cout << "NIE" << endl;

  return 0;
}
#endif