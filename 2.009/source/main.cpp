#include <iostream>
#include <cmath>

using namespace std;

/**
 * Sprawdzanie czy liczba naturalna jest palindromem, a następnie czy jest palindromem w systemie
 * dwójkowym.
 */

int get_digit(long source, int index, int base)
{
  return (source / (int) pow(base, index)) % base;
}

bool is_palindrome(int x, int base)
{
  int size;
  if(base == 2)
    size = log2(x);
  else if(base == 10)
    size = log10(x);
  else
    return false;
  size++;

  bool result = true;
  for(int i = 0; i < size / 2 && result; i++)
  {
    if(get_digit(x, i, base) != get_digit(x, size - i - 1, base))
      result = false;
  }

  return result;
}

#ifndef TEST
int main()
{
  int x;
  cin >> x;

  bool is_dec_palindrome = is_palindrome(x, 10);
  bool is_bin_palindrome = is_palindrome(x, 2);

  if(is_dec_palindrome)
    cout << "TAK" << endl;
  else
    cout << "NIE" << endl;

  if(is_bin_palindrome)
    cout << "TAK" << endl;
  else
    cout << "NIE" << endl;

  return 0;
}
#endif