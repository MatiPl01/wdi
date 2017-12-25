#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
  double result       = sqrt(0.5);
  double last_element = result;
  double delta        = 1;
  while(delta != 0)
  {
    last_element      = sqrt(0.5 + 0.5 * last_element);
    double new_result = result * last_element;
    delta             = new_result - result;
    result            = new_result;
  }

  printf("%f\n", 2 / result);
  return 0;
}