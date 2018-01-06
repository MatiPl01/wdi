#include "myMath.h"

int int_sqrt(int n)
{
  int sqrt   = 0;
  int tmp    = 1;
  int result = 0;

  while(sqrt <= n)
  {
    sqrt += tmp;
    tmp += 2;
    result++;
  }

  return result - 1;
}

bool is_prime(int n)
{
  if(n == 1)
  {
    return false;
  }
  else if(n == 2)
  {
    return true;
  }
  else if(n % 2 == 0)
  {
    return false;
  }
  else
  {
    for(int i = 3; i <= int_sqrt(n); i += 2)
    {
      if(n % i == 0)
      {
        return false;
      }
    }
  }

  return true;
}

int nwd(int a, int b)
{
  while(a != b)
  {
    if(a > b)
      a -= b;
    else if(b > a)
      b -= a;
  }
  return a;
}

int nww(int a, int b)
{
  return a * b / nwd(a, b);
}

double cos(double x)
{
  const int N = 100;

  double cos       = 1;
  double numerator = 1;
  double factorial = 2;
  int    sign      = -1;

  for(int i = 1; i < N * 2; i += 2)
  {
    numerator *= x * x;
    cos += sign * (numerator) / factorial;
    factorial = factorial * (i + 2) * (i + 3);
    sign *= -1;
  }
}