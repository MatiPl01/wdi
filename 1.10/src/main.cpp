#include <cstdio>
#include <iostream>
#include "myMath.h"

using namespace std;

int main(void)
{
	int a, b, c;
	cin >> a >> b >> c;

	printf("%d\n", nww(nww(a, b), c));

	return 0;
}

