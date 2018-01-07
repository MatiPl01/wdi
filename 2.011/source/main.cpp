#include <iostream>

using namespace std;

/**
 * Napisać program, który wyznacza ostatnia niezerową cyfra N! Program powinien działać dla N rzędu
 * 1000000.
 */

int calculate_last_digit_of_factorial(int N)
{
  int result = 1;
  int last_result = 1;
  int mask   = 10;
  int result_mask_offset = 10;

  for(int i = 1; i <= N; i++)
  {
  	if(i == 10)
  		result_mask_offset *= 10;
  	cout << i << endl;
    result = last_result*i;
    cout << result << endl;
    while(result % mask == 0)
      mask *= 10;
    last_result = result % (mask * result_mask_offset);
    last_result /= mask / 10;
    cout << last_result << endl;
    result %= mask;
    result /= mask / 10;
    cout << result << endl;
    mask = 10;
    cout << endl;
  }

  return result;
}

#ifndef TEST
int main()
{
  int N;
  cin >> N;

  cout << calculate_last_digit_of_factorial(N) << endl;

  return 0;
}
#endif