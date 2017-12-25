#define TEST

#include "unity.h"
#include "../source/main.cpp"

void test_smallest_generators(void)
{
  pair_t result = smallest_generators(2017);
  TEST_ASSERT_EQUAL(result.a, 7);
  TEST_ASSERT_EQUAL(result.b, 48);
}