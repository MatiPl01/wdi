#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

double calc_next_a(double a, double b)
{
  return sqrt(a * b);
}

double calc_next_b(double a, double b)
{
  return (a + b) / 2.0;
}

double arithmetic_geometric_mean(double a, double b)
{
  const double epsilon = 0.1;
  while(abs(a - b) > epsilon)
  {
    a = calc_next_a(a, b);
    b = calc_next_b(a, b);
  }
  return (a + b) / 2;
}

#ifndef TEST
int main()
{
  double a, b;
  cin >> a >> b;
  double c = arithmetic_geometric_mean(a, b);
  cout << c;

  return 0;
}
#endif