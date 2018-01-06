#include <iostream>

using namespace std;

/**
 * Napisz program wczytujący liczbę naturalną z klawiatury i odpowiadający na pytanie, czy liczba ta
 * jest wielokrotnością dowolnego wyrazu ciągu danego wzorem A(n)=3\*A(n-1)+1, a pierwszy wyraz jest
 * równy 2.
 */

#ifndef TEST
int main()
{
  int  n;
  int  wyraz;
  int  A      = 2;
  bool result = false;

  cin >> n;
  wyraz = A;

  while(wyraz <= n && !result)
  {
    if(n % wyraz == 0)
      result = true;
    else
      wyraz = 3 * A + 1;
  }

  if(result)
    cout << "TAK" << endl;
  else
    cout << "NIE" << endl;

  return 0;
}
#endif