#include <iostream>

using namespace std;

/**
 * Dane są dwie liczby naturalne z których budujemy trzecią liczbę. W budowanej liczbie muszą
 * wystąpić wszystkie cyfry występujące w liczbach wejściowych. Wzajemna kolejność cyfr każdej z
 * liczb wejściowych musi być zachowana. Na przykład mając liczby 123 i 75 możemy zbudować liczby
 * 12375, 17523, 75123, 17253,itd. Proszę napisać funkcję która wyznaczy ile liczb pierwszych można
 * zbudować z dwóch zadanych liczb.
 */

bool is_prime(int n)
{
  if(n == 1)
  {
    return false;
  }
  else if(n == 2)
  {
    return true;
  }
  else if(n % 2 == 0)
  {
    return false;
  }
  else
  {
    for(int i = 3; i * i <= n; i += 2)
    {
      if(n % i == 0)
      {
        return false;
      }
    }
  }

  return true;
}

int search(int a, int b, int result, int level)
{
  int score = 0;
  if(a > 0)
    score += search(a / 10, b, result + (a % 10) * level, level * 10);
  if(b > 0)
    score += search(a, b / 10, result + (b % 10) * level, level * 10);
  if(a == 0 && b == 0 && is_prime(result))
    score = 1;
  return score;
}

#ifndef TEST
int main()
{
  int a, b;
  cin >> a >> b;

  cout << search(a, b, 0, 1) << endl;

  return 0;
}
#endif