#include <iostream>

using namespace std;

/**
 * Napisz program wczytujący liczbę naturalną z klawiatury i odpowiadający na pytanie, czy liczba ta
 * jest wielokrotnością dowolnego wyrazu ciągu danego wzorem A(n)=n\*n+n+1.
 */

int A(int n)
{
  return n * n + n + 1;
}

#ifndef TEST
int main()
{
  int  n;
  int  wyraz;
  int  i      = 1;
  bool result = false;

  cin >> n;
  wyraz = A(i++);

  while(wyraz <= n && !result)
  {
    if(n % wyraz == 0)
      result = true;
    else
      wyraz = A(i++);
  }

  if(result)
    cout << "TAK" << endl;
  else
    cout << "NIE" << endl;

  return 0;
}
#endif