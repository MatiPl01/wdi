#include <iostream>

#include "main.h"

using namespace std;

#ifndef TEST
int main()
{
	int a, b;
	cin >> a >> b;

	int c = add(a, b);

	cout << c;

	return 0;
}
#endif

int add(int a, int b)
{
	return a + b;
}