#define TEST

#include "unity.h"
#include "../source/main.cpp"

#include <cstdlib>

void test_heapify(void)
{
  int output[] = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
  int input[] = {16, 8, 10, 14, 7, 9, 3, 2, 4, 1};
  size_t N = sizeof(input)/sizeof(int);

  heapify(input, N, 1);
  TEST_ASSERT_EQUAL_INT_ARRAY(output, input, sizeof(output)/sizeof(int));
}

void test_extract(void)
{
  int input[] = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
  size_t N = sizeof(input)/sizeof(int);

  int result = extract_max(input, N);

  TEST_ASSERT_EQUAL(result, 16);

  for(int i = 0; i < N-1; i++)
  {
    if(left(i) < N-1)
      TEST_ASSERT_TRUE(input[left(i)] <= input[i])
    if(right(i) < N-1)
      TEST_ASSERT_TRUE(input[right(i)] <= input[i])
  }
}

void test_build_heap(void)
{
  int    input[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
  size_t N = sizeof(input)/sizeof(int);

  build_heap(input, N);

  for(int i = 0; i < N; i++)
  {
    if(left(i) < N)
      TEST_ASSERT_TRUE(input[left(i)] <= input[i])
    if(right(i) < N)
      TEST_ASSERT_TRUE(input[right(i)] <= input[i])
  }
}

void test_test(void)
{
  int output[] = {1, 2, 3};
  int input[]  = {3, 2, 1};

  heap_sort(input, 3);

  TEST_ASSERT_EQUAL_INT_ARRAY(output, input, 3);
}

void test_rand(void)
{
  static const size_t N = 10000;
  int                 input[N];

  srand(0);
  for(int i  = 0; i < N; i++)
    input[i] = rand();

  heap_sort(input, N);

  for(int i = 1; i < N; i++)
    TEST_ASSERT_TRUE(input[i - 1] <= input[i])
}