#define TEST

#include "unity.h"
#include "../source/main.cpp"

#include <cstdlib>

void test_test(void)
{
  int output[] = {1, 2, 3};
  int input[]  = {3, 2, 1};

  quick_sort(input, 0, 2);

  TEST_ASSERT_EQUAL_INT_ARRAY(output, input, 3);
}

// void test_test2(void)
// {
//   int output[] = {1,1,2,2,3,3};
//   int input[]  = {2,3,1,1,3,2};

//   quick_sort(input, 0, 5);

//   TEST_ASSERT_EQUAL_INT_ARRAY(output, input, 6);
// }

void test_test3(void)
{
  int input[] = {5,3,2,6,4,1,3,7};
  int output[]  = {1,2,3,3,4,5,6,7};

  quick_sort(input, 0, 7);

  TEST_ASSERT_EQUAL_INT_ARRAY(output, input, 8);
}

// void test_rand(void)
// {
//   static const size_t N = 10000;
//   int                 input[N];

//   srand(0);
//   for(int i  = 0; i < N; i++)
//     input[i] = rand();

//   quick_sort(input, 0, N-1);

//   for(int i = 1; i < N; i++)
//     TEST_ASSERT_TRUE(input[i - 1] <= input[i])
// }