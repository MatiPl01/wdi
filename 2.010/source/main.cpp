#include <iostream>
using namespace std;

/**
 * Liczba dwu-trzy-piątkowa w rozkładzie na czynniki pierwsze nie posiada innych czynników niż
 * 2,3,5. Jedynka też jest taką liczbą. Napisz program, który wylicza ile takich liczb znajduje się
 * w przedziale od 1 do N włącznie.
 */

int how_many_2_3_5(int start, int N)
{
  int two   = 0;
  int three = 0;
  int five  = 0;
  if(start * 2 <= N)
  {
    two = how_many_2_3_5(start * 2, N);
    two++;
  }
  if(start * 3 <= N)
  {
    three = how_many_2_3_5(start * 3, N);
    three++;
  }
  if(start * 5 <= N)
  {
    five = how_many_2_3_5(start * 5, N);
    five++;
  }

  return two + three + five;
}

#ifndef TEST
int main()
{
  int N;
  cin >> N;
  cout << how_many_2_3_5(1, N) << endl;
  return 0;
}
#endif