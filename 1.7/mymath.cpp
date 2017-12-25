#include "mymath.h"

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