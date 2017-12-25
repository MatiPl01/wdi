#define TEST

#include "unity.h"
#include "../source/main.cpp"

void test_test(void)
{
  TEST_ASSERT_EQUAL(1, sqrt(1));
  TEST_ASSERT_EQUAL(2, sqrt(4));
  TEST_ASSERT_EQUAL(3, sqrt(9));
  TEST_ASSERT_EQUAL(4, sqrt(16));
  TEST_ASSERT_EQUAL(5, sqrt(25));
  TEST_ASSERT_EQUAL(6, sqrt(36));
  TEST_ASSERT_EQUAL(7, sqrt(49));
  TEST_ASSERT_EQUAL(8, sqrt(64));
  TEST_ASSERT_EQUAL(9, sqrt(81));
  TEST_ASSERT_EQUAL(10, sqrt(100));
  TEST_ASSERT_EQUAL(11, sqrt(121));
  TEST_ASSERT_EQUAL(12, sqrt(144));
  TEST_ASSERT_EQUAL(13, sqrt(169));
  TEST_ASSERT_EQUAL(14, sqrt(196));
  TEST_ASSERT_EQUAL(15, sqrt(225));
  TEST_ASSERT_EQUAL(16, sqrt(256));
  TEST_ASSERT_EQUAL(17, sqrt(289));
  TEST_ASSERT_EQUAL(18, sqrt(324));
  TEST_ASSERT_EQUAL(19, sqrt(361));
  TEST_ASSERT_EQUAL(20, sqrt(400));
}