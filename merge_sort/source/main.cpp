#include <iostream>
#include <cstddef>
#include <cstdio>

using namespace std;

void merge(int * tab, size_t begining, size_t half, size_t end)
{
  size_t index_left = begining;
  size_t index_right = half+1;

  int * new_tab = new int[end-begining+1];
  size_t new_tab_index = 0;

  while(index_left <= half && index_right <= end)
  {
    if(tab[index_left] > tab[index_right])
    {
      new_tab[new_tab_index] = tab[index_right];
      new_tab_index++;
      index_right++;
    }
    else if(tab[index_right] > tab[index_left])
    {
      new_tab[new_tab_index] = tab[index_left];
      new_tab_index++;
      index_left++;
    }
  }

  while(index_left <= half)
  {
    new_tab[new_tab_index] = tab[index_left];
    new_tab_index++;
    index_left++;
  }

  while(index_right <= end)
  {
    new_tab[new_tab_index] = tab[index_right];
    new_tab_index++;
    index_right++;
  }

  for(int i = 0; i < end-begining+1; i++)
  {
    tab[begining+i] = new_tab[i];
  }

  delete new_tab;
}

void merge_sort(int * tab, size_t begining, size_t end)
{
  if(begining < end)
  {
    size_t half = (end + begining)/2;
  
    merge_sort(tab, begining, half);
    merge_sort(tab, half + 1, end);
    merge(tab, begining, half, end);
  }
}

#ifndef TEST
int main()
{
  return 0;
}
#endif