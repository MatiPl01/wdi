#include <cstdio>
#include <iostream>

using namespace std;

double f(double x)
{
  return (x * x * x) - 2017;
}

double abs(double a)
{
  return a < 0 ? -a : a;
}

int main(void)
{
  double beg = 0, end = 2017;

  double y_beg = f(beg);
  double y_end = f(end);
  if(y_beg > y_end)
  {
    double tmp = end;
    end        = beg;
    beg        = end;
  }

  double epsilon = 0.0000000001;
  double avr     = (beg + end) / 2;
  double y       = f(avr);

  while(abs(y) > epsilon)
  {
    if(y < 0)
      beg = avr;
    else
      end = avr;
    avr   = (beg + end) / 2;
    y     = f(avr);
  }

  printf("%f\n", avr);

  return 0;
}