#include <iostream>
#include <cstddef>
#include <cstdio>

using namespace std;

static inline int parent(size_t i) { return (i+1)/2 - 1;       }
static inline int left(size_t i)   { return (i+1)*2 - 1;       }
static inline int right(size_t i)  { return (i+1)*2; }

void heapify(int * heap, size_t heap_size, size_t parent_index)
{
  size_t left_son_index = left(parent_index);
  size_t right_son_index = right(parent_index);
  size_t largest_element_index;

  largest_element_index = parent_index;
  if(left_son_index < heap_size && heap[left_son_index] > heap[parent_index])
  {
    largest_element_index = left_son_index;
  }
  if(right_son_index < heap_size && heap[right_son_index] > heap[largest_element_index])
  {
    largest_element_index = right_son_index;
  }

  if(largest_element_index != parent_index)
  {
    int tmp = heap[largest_element_index];
    heap[largest_element_index] = heap[parent_index];
    heap[parent_index] = tmp;
    heapify(heap, heap_size, largest_element_index);
  }
}

void build_heap(int * heap, size_t heap_size)
{
  for(int i = heap_size -1; i>=0; i--)
    heapify(heap, heap_size, i);
}

int extract_max(int * tab, size_t len)
{
  int max = tab[0];
  int tmp = tab[len-1];
  tab[len-1] = tab[0];
  tab[0] = tmp;
  len -= 1;
  heapify(tab, len, 0);

  return max;
}

void insert(int * tab, size_t len, int new_element)
{
  len += 1;
  i = len - 1;
  while(i > 0 && tab[parent(i)] < new_element)
  {
    tab[i] = tab[parent(i)];
  }
  tab[i] = new_element;
}

void heap_sort(int * tab, size_t len)
{
  build_heap(tab, len);
  for(int i = len-1; i >= 0; i--)
  {
    int tmp = tab[i];
    tab[i] = tab[0];
    tab[0] = tmp;
    len -= 1;
    heapify(tab, len, 0);
  }
}

#ifndef TEST
int main()
{
  return 0;
}
#endif