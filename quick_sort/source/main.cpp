#include <iostream>
#include <cstddef>
#include <cstdio>

using namespace std;

size_t partiotion(int * tab, size_t start, size_t end)
{
  int pivot_value = tab[start];
  int left_index = start;
  int right_index = end;

  while(true)
  {
    for(int i = start; i <= end; i++)
      printf("\t\t%d ", tab[i]);

    while(tab[right_index] >= pivot_value && right_index > left_index)
      right_index--;
    while(tab[left_index] < pivot_value && right_index > left_index)
      left_index++;

    printf("\n%d %d %d\n", left_index, right_index, pivot_value);
    if(tab[left_index] > tab[right_index])
    {
      // printf("DUPA\n");
      int tmp = tab[left_index];
      tab[left_index] = tab[right_index];
      tab[right_index] = tmp;
      // left_index++;
      // right_index++;
    }
    else
    {
      return right_index;
    }
  }
}

void quick_sort(int * tab, size_t start, size_t end)
{
  if(start < end)
  {
    int pivot = partiotion(tab, start, end);
    printf("%d\n", pivot);
    int x;
    scanf("%d", &x);
    quick_sort(tab, start, pivot);
    quick_sort(tab, pivot+1, end);
  }
}

#ifndef TEST
int main()
{
  return 0;
}
#endif