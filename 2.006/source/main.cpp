#include <iostream>
#include <deque>

using namespace std;

/**
 * Proszę napisać program, który wczytuje wprowadzany z klawiatury ciąg liczb naturalnych
 * zakończonych zerem stanowiącym wyłącznie znacznik końca danych. Program powinien wypisać te
 * elementy ciągu które są równe średniej arytmetycznej z 4 najbliższych sąsiadów. Na przykład dla
 * ciągu: 2,3,2,7,1,2,4,8,5,2,2,4,3,9,5,4,0 powinny zostać wypisane podkreślone liczby. Można
 * założyć, że w ciągu znajduje się co najmniej 5 elementów.
 */

#ifndef TEST
int main()
{
  deque< int > data;
  do
  {
    int digit;
    cin >> digit;
    data.push_back(digit);
  } while(data.back() != 0);

  for(int i = 4; i < data.size() - 1; i++)
  {
    int el1 = data[i - 4];
    int el2 = data[i - 3];
    int el3 = data[i - 2];
    int el4 = data[i - 1];
    int el5 = data[i];
    if((el1 + el2 + el4 + el5) / 4 == el3)
      cout << el3 << " ";
  }

  return 0;
}
#endif