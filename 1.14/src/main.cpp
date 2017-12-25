#include <cstdio>
#include <iostream>

using namespace std;

float abs(float a)
{
  return a < 0 ? -a : a;
}

int main(void)
{
  float n;
  cin >> n;

  float a       = n / 2;
  float epsilon = 0.001;

  while(abs((n / a) - a) > epsilon)
  {
    a = (a + (n / a)) / 2;
  }

  printf("%f\n", a);
  return 0;
}