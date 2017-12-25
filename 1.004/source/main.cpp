#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>

#include "fibonacciGenerator.h"

using namespace std;

/**
 * Napisać program sprawdzający czy istnieje podciąg ciągu Fibonacciego o sumie równej
 * numerowi bieżącego roku.
 */

bool has_substring(vector<int> & sequence);
bool substring_searcher(vector<int> & sequence, int index, bool * summary);

const int N = 2017;

#ifndef TEST
int main(void)
{
  FibonacciGenerator * gen = new FibonacciGenerator();
  vector<int> sequence;
  int element;
  do
  {
    element = gen->next();
    sequence.push_back(element);
  } while(element < N);

  bool result = has_substring(sequence);
  cout << result << endl;
}
#endif

bool has_substring(vector<int> & sequence)
{
  bool * summary = new bool[sequence.size()];
  memset(summary, 0, sequence.size() * sizeof(bool));
  bool result = substring_searcher(sequence, 0, summary);
  delete summary;
  return result;
}

bool substring_searcher(vector<int> & sequence, int index, bool * summary)
{
  if(index == sequence.size())
  {
    int sum = 0;
    for(int i = 0; i < index; i++)
    {
      if(summary[i])
        sum += sequence[i];
    }
    return sum == N;
  }
  else
  {
    bool   result   = false;  
    bool * summary1 = new bool[sequence.size()];
    bool * summary2 = new bool[sequence.size()];

    memcpy(summary1, summary, sequence.size() * sizeof(bool));
    memcpy(summary2, summary, sequence.size() * sizeof(bool));

    summary1[index] = false;
    summary2[index] = true;

    result |= substring_searcher(sequence, index + 1, summary1);
    result |= substring_searcher(sequence, index + 1, summary2);

    delete summary1;
    delete summary2;

    return result;
  }
}