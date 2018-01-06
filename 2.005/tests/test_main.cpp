#define TEST

#include "unity.h"
#include "../source/main.cpp"

void test_get_digit(void)
{
  TEST_ASSERT_EQUAL(0, get_digit(9876543210, 0));
  TEST_ASSERT_EQUAL(1, get_digit(9876543210, 1));
  TEST_ASSERT_EQUAL(2, get_digit(9876543210, 2));
  TEST_ASSERT_EQUAL(3, get_digit(9876543210, 3));
  TEST_ASSERT_EQUAL(4, get_digit(9876543210, 4));
  TEST_ASSERT_EQUAL(5, get_digit(9876543210, 5));
  TEST_ASSERT_EQUAL(6, get_digit(9876543210, 6));
  TEST_ASSERT_EQUAL(7, get_digit(9876543210, 7));
  TEST_ASSERT_EQUAL(8, get_digit(9876543210, 8));
  TEST_ASSERT_EQUAL(9, get_digit(9876543210, 9));
}