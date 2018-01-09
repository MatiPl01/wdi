#include <iostream>

using namespace std;

/*
 * Napisać program poszukujący trójkątów Pitagorejskich.
 */

#ifndef TEST
int main()
{
  int N;
  cin >> N;

  for(int a = 1; a <= N; a++)
  {
    int c = 1;
    for(int b = a; b <= N; b++)
    {
      while(c * c < a * a + b * b)
        c++;
      if(c * c <= a * a + b * b)
        cout << a << "\t" << b << "\t" << c << endl;
    }
  }

  return 0;
}
#endif