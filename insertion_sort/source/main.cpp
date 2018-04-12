#include <iostream>
#include <cstddef>
#include <cstdio>

using namespace std;

void insertion_sort(int * tab, size_t len)
{
  for(int i = 1; i < len; i++)
  {
    int picked_value = tab[i];
    for(int x = i - 1; x >= 0; x--)
    {
      if(tab[x] > picked_value)
      {
        tab[x + 1] = tab[x];
        tab[x]     = picked_value;
      }
      else
      {
        tab[x + 1] = picked_value;
        break;
      }
    }
  }
}

#ifndef TEST
int main()
{
  return 0;
}
#endif