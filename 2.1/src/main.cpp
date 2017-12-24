#include <cstdio>
#include <iostream>

using namespace std;

//Oblicz e z rozwinięcia w szereg z dokładnościa do 1000 cyfr dziesiętnych

//Liczba od najbardziej znaczacych
//
void dzielenie(int liczba[], size_t liczba_len, int dzielnik, int * index_start)
{
	for(int i = 0; i < liczba_len; i++)
	{
		int reszta = liczba[i] % dzielnik;
		liczba[i] /= dzielnik;
		if(i+1 != liczba_len)
		{
			liczba[i+1] += reszta * 10;
		}
		if(i == *index_start && liczba[i] == 0)
			*index_start = i + 1;
	}
}

void fix_digit(int a[], int len_a, int start_index)
{
	for(int i = start_index; i >= 1; i--)
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
		fix_digit(b, b_len, i);
	}
}

int main(void)
{
	printf("%-20s  |  %-20s  |  %-20s  \n", "Name", "Min. left stack", "State");
}

#ifndef TEST
// int main(void)
// {
// 	const int dokladnosc = 2000;
// 	int e[dokladnosc] = {0};
// 	int a[dokladnosc] = {0};
// 	a[0] = 1;

// 	int index_start = 0;
// 	int i = 1;

// 	while(index_start < dokladnosc)
// 	{
// 		dzielenie(a, dokladnosc, i++, &index_start);
// 		dodawanie(a, dokladnosc, e, dokladnosc, index_start);
// 	}

// 	printf("2.");
// 	for(int i = 0; i < dokladnosc; i++)
// 		printf("%d", e[i]);

// 	printf("\n");

// 	return 0;
// }
#endif