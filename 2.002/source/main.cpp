#include <iostream>

using namespace std;

/**
 * Napisz program wczytujący liczbę naturalną z klawiatury i odpowiadający na pytanie, czy liczba ta
 * jest iloczynem dowolnych dwóch wyrazów ciągu Fibonacciego.
 */

int fibbonacci()
{
  static int n  = 0;
  static int f1 = 0;
  static int f2 = 1;

  if(n == 0)
  {
    n++;
    return 0;
  }
  else if(n == 1)
  {
    n++;
    return 1;
  }
  else
  {
    n++;
    int result = f1 + f2;
    int f2_tmp = f2;
    f2         = f1 + f2;
    f1         = f2_tmp;
    return result;
  }
}

#ifndef TEST
int main()
{
  int a;
  cin >> a;

  int  fibbonacci_prev = fibbonacci();
  int  fibbonacci_curr = fibbonacci();
  bool result          = false;

  while(a >= fibbonacci_curr && !result)
  {
    if(fibbonacci_prev * fibbonacci_curr == a)
      result = true;

    fibbonacci_prev = fibbonacci_curr;
    fibbonacci_curr = fibbonacci();
  }

  if(result)
    cout << "TAK" << endl;
  else
    cout << "NIE" << endl;

  return 0;
}
#endif