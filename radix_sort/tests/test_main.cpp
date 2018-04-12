#define TEST

#include "unity.h"
#include "../source/main.cpp"

#include <cstdlib>

void test_test(void)
{
  int expected_output[] = {1, 2, 3};
  int input[]  = {3, 2, 1};
  int output[]  = {3, 2, 1};

  radix(input, output, 3, 4);

  TEST_ASSERT_EQUAL_INT_ARRAY(expected_output, output, 3);
}