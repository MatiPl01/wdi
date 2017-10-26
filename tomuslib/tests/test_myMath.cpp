#include "unity.h"
#include <cstdio>

#include "myMath.cpp"

void test_int_sqrt(void)
{
	TEST_ASSERT_EQUAL(1,  int_sqrt(1));
	TEST_ASSERT_EQUAL(2,  int_sqrt(4));
	TEST_ASSERT_EQUAL(2,  int_sqrt(5));
	TEST_ASSERT_EQUAL(2,  int_sqrt(8));
	TEST_ASSERT_EQUAL(10, int_sqrt(100));
	TEST_ASSERT_EQUAL(4,  int_sqrt(16));
	TEST_ASSERT_EQUAL(4,  int_sqrt(17));
	TEST_ASSERT_EQUAL(3,  int_sqrt(15));
}

void test_is_prime(void)
{
	int primes[] = { 5, 7,  11, 13, 17, 
				    19, 23, 29, 31, 37, 41, 
				    43, 47, 53, 59, 61, 67, 
				    71, 73, 79, 83, 89, 97};
		    
	for(int i = 0; i < sizeof(primes)/sizeof(int); i++)
	{
		TEST_ASSERT_TRUE(is_prime(primes[i]));
		TEST_ASSERT_FALSE(is_prime(primes[i]+1));
		TEST_ASSERT_FALSE(is_prime(primes[i]-1));
	}

	TEST_ASSERT_TRUE(is_prime(2));
	TEST_ASSERT_TRUE(is_prime(3));
}