#include <iostream>
using namespace std;

/**
 * Napisać program generujący elementy ciągu Fibonaciego mniejsze od miliona.
 */

int main()
{
  int f0 = 1;
  int f1 = 1;

  cout << 0 << endl << f0 << endl << f1 << endl;

  while(f0 + f1 < 1000000)
  {
    int tmp = f0 + f1;
    cout << tmp << endl;
    f0 = f1;
    f1 = tmp;
  }

  return 0;
}