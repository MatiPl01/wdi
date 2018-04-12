#define TEST

#include "unity.h"
#include "../source/main.cpp"

#include <cstdlib>

void test_test(void)
{
  int expected_output[] = {1, 2, 3};
  int input[]  = {3, 2, 1};
  int output[]  = {3, 2, 1};

  insertion_sort(input, output, 3, 4);

  TEST_ASSERT_EQUAL_INT_ARRAY(expected_output, output, 3);
}

// void test_rand(void)
// {
//   static const size_t N = 10000;
//   int                 input[N];

//   srand(0);
//   for(int i  = 0; i < N; i++)
//     input[i] = rand();

//   insertion_sort(input, N);

//   for(int i = 1; i < N; i++)
//     TEST_ASSERT_TRUE(input[i - 1] <= input[i])
// }