#include "unity.h"

int dzielenie(int liczba[], size_t liczba_len, int dzielnik, int index_start)
{
	for(int i = 0; i < liczba_len; i++)
	{
		int reszta = liczba[i] % dzielnik;
		liczba[i] /= dzielnik;
		if(i+1 != liczba_len)
		{
			liczba[i+1] += reszta * 10;
		}
		if(i == index_start && liczba[i] == 0)
			index_start = i + 1;
	}

	return index_start;
}

void fix_digit(int a[], int len_a)
{
	for(int i = len_a - 1; i >= 1; i--)
	{
		if(a[i] >= 10)
		{
			a[i-1] += a[i] / 10;
			a[i]    = a[i] % 10;
		}
	}
}

void dodawanie(int a[], size_t a_len, int b[], size_t b_len, int index_start)
{
	for(int i = a_len - 1; i >= index_start; i--)
	{
		b[i] += a[i];
		fix_digit(b, b_len);
	}
}

void test_dzielenie(void)
{
	int a[] = {1, 0, 0};
	int w[] = {0, 5, 0};

	const int rozmiar = sizeof(a)/sizeof(int);
	const int dzielnik = 2;
	const int start = 0;
	const int end   = 1;
	int val = dzielenie(a, rozmiar, dzielnik, start);

	TEST_ASSERT_EQUAL(val, end);
	TEST_ASSERT_EQUAL_INT_ARRAY(a, w, rozmiar);
}

void test_dzielenie2(void)
{
	int a[] = {2, 5, 6};
	int w[] = {0, 0, 2};

	const int rozmiar = sizeof(a)/sizeof(int);
	const int dzielnik = 128;
	const int start = 0;
	const int end   = 2;
	int val = dzielenie(a, rozmiar, dzielnik, start);

	TEST_ASSERT_EQUAL(val, end);
	TEST_ASSERT_EQUAL_INT_ARRAY(a, w, rozmiar);
}

void test_fix_digit(void)
{
	int a[] = {0, 9, 15};
	int w[] = {1, 0, 5};

	const int rozmiar = sizeof(a)/sizeof(int);
	fix_digit(a, rozmiar);

	TEST_ASSERT_EQUAL_INT_ARRAY(a, w, rozmiar);
}

void test_dodawanie(void)
{
	int a[]     = {0, 0, 1};
	int b[]     = {0, 0, 1};
	int wynik[] = {0, 0, 2};

	const int rozmiar_a = sizeof(a)/sizeof(int);
	const int rozmiar_b = sizeof(b)/sizeof(int);
	const int rozmiar = sizeof(wynik)/sizeof(int);

	dodawanie(a, rozmiar_a, b, rozmiar_b, 2);

	TEST_ASSERT_EQUAL_INT_ARRAY(b, wynik, rozmiar);
}

void test_dodawanie2(void)
{
	int a[]     = {0, 0, 5};
	int b[]     = {0, 0, 5};
	int wynik[] = {0, 1, 0};

	const int rozmiar_a = sizeof(a)/sizeof(int);
	const int rozmiar_b = sizeof(b)/sizeof(int);
	const int rozmiar   = sizeof(wynik)/sizeof(int);

	dodawanie(a, rozmiar_a, b, rozmiar_b, 2);

	TEST_ASSERT_EQUAL_INT_ARRAY(b, wynik, rozmiar);
}