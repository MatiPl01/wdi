#define TEST

#include "unity.h"
#include "../source/main.cpp"

void test_pow(void)
{
  TEST_ASSERT_EQUAL(1, pow(1, 2));
  TEST_ASSERT_EQUAL(4, pow(2, 2));
  TEST_ASSERT_EQUAL(9, pow(3, 2));
  TEST_ASSERT_EQUAL(16, pow(4, 2));
  TEST_ASSERT_EQUAL(25, pow(5, 2));
  TEST_ASSERT_EQUAL(36, pow(6, 2));
  TEST_ASSERT_EQUAL(49, pow(7, 2));
  TEST_ASSERT_EQUAL(64, pow(8, 2));
  TEST_ASSERT_EQUAL(81, pow(9, 2));
  TEST_ASSERT_EQUAL(100, pow(10, 2));
}

void test_nwd(void)
{
  TEST_ASSERT_EQUAL(51, nwd(1989, 867));
}