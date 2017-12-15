#include <iostream>

#include "main.h"

using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;

	int c = add(a, b);

	cout << c;

	return 0;
}

int add(int a, int b)
{
	return a + b;
}