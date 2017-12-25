#include <cstdio>
#include <iostream>

using namespace std;

int main(void)
{
  int    i       = 1;
  double element = 1;
  double silnia  = 1;
  double e       = 0;
  while(element != 0)
  {
    element = 1 / silnia;
    silnia  = silnia * i++;
    e += element;
  }

  printf("%f\n", e);

  return 0;
}