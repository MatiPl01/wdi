#define TEST

#include "unity.h"
#include "../source/main.cpp"

#include <cstdlib>

void test_test(void)
{
  int output[] = {1, 2, 3, 4};
  int input[]  = {4, 3, 2, 1};

  merge_sort(input, 0, 3);

  TEST_ASSERT_EQUAL_INT_ARRAY(output, input, 3);
}

void test_rand(void)
{
  static const size_t N = 10000;
  int                 input[N];

  srand(0);
  for(int i  = 0; i < N; i++)
    input[i] = rand();

  merge_sort(input, 0, N-1);

  for(int i = 1; i < N; i++)
    TEST_ASSERT_TRUE(input[i - 1] <= input[i])
}