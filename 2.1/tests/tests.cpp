#define TEST

#include "unity.h"
#include "main.cpp"

void test_dzielenie(void)
{
  int a[] = {1, 0, 0};
  int w[] = {0, 5, 0};

  const int rozmiar  = sizeof(a) / sizeof(int);
  const int dzielnik = 2;
  int       start    = 0;
  const int end      = 1;
  dzielenie(a, rozmiar, dzielnik, &start);

  TEST_ASSERT_EQUAL(start, end);
  TEST_ASSERT_EQUAL_INT_ARRAY(a, w, rozmiar);
}

void test_dzielenie2(void)
{
  int a[] = {2, 5, 6};
  int w[] = {0, 0, 2};

  const int rozmiar  = sizeof(a) / sizeof(int);
  const int dzielnik = 128;
  int       start    = 0;
  const int end      = 2;
  dzielenie(a, rozmiar, dzielnik, &start);

  TEST_ASSERT_EQUAL(start, end);
  TEST_ASSERT_EQUAL_INT_ARRAY(a, w, rozmiar);
}

void test_fix_digit(void)
{
  int a[] = {0, 9, 15};
  int w[] = {1, 0, 5};

  const int rozmiar = sizeof(a) / sizeof(int);
  fix_digit(a, rozmiar, rozmiar - 1);

  TEST_ASSERT_EQUAL_INT_ARRAY(a, w, rozmiar);
}

void test_dodawanie(void)
{
  int a[]     = {0, 0, 1};
  int b[]     = {0, 0, 1};
  int wynik[] = {0, 0, 2};

  const int rozmiar_a = sizeof(a) / sizeof(int);
  const int rozmiar_b = sizeof(b) / sizeof(int);
  const int rozmiar   = sizeof(wynik) / sizeof(int);

  dodawanie(a, rozmiar_a, b, rozmiar_b, 2);

  TEST_ASSERT_EQUAL_INT_ARRAY(b, wynik, rozmiar);
}

void test_dodawanie2(void)
{
  int a[]     = {0, 0, 5};
  int b[]     = {0, 0, 5};
  int wynik[] = {0, 1, 0};

  const int rozmiar_a = sizeof(a) / sizeof(int);
  const int rozmiar_b = sizeof(b) / sizeof(int);
  const int rozmiar   = sizeof(wynik) / sizeof(int);

  dodawanie(a, rozmiar_a, b, rozmiar_b, 2);

  TEST_ASSERT_EQUAL_INT_ARRAY(b, wynik, rozmiar);
}