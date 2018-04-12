#include <iostream>
#include <cstddef>
#include <cstdio>

using namespace std;

void counting(int * input, int * output, size_t len, size_t range, int mask)
{
  int * buffer = new int[range];

  for(int i = 0; i < range; i++)
  {
    buffer[range] = 0;
  }

  for(int i = 0; i < len; i++)
  {
    buffer[(input[i]/mask)%10]++;
  }

  for(int i = 0; i < range-1; i++)
  {
    buffer[i+1] += buffer[i];
  }

  for(int i = len-1; i >= 0; i--)
  {
    output[buffer[(input[i]/mask)%10] -1] = input[i];
    buffer[(input[i]/mask)%10] -= 1;
  }
}



#ifndef TEST
int main()
{
  return 0;
}
#endif