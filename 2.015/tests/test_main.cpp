#define TEST

#include "unity.h"
#include "../source/main.cpp"

void test_calculate_sum_of_digits(void)
{
  TEST_ASSERT_EQUAL(6, calculate_sum_of_digits(123));
}