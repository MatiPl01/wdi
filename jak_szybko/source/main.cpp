#include <iostream>
#include <vector>
#include <utility>
#include <climits>
#include <algorithm>

using namespace std;

const int INF = INT_MAX / 2;

typedef struct Segment {
    int town, travel_time;
} Segment;

typedef struct Line {
    Segment* segments;
    int number, length, start_town;
} Line;

Line* newLine(int number, int length, int start_town) {
  Line* l = new Line;
  l->number = number;
  l->length = length;
  l->start_town = start_town;
  l->segments = new Segment[length];
  return l;
}

typedef struct Node {
    int town, id;
    vector< pair<Node*, int> > neighbours;
} Node;

int** calculateTimesMatrix(Line** lines, int lines_no, int towns) {
  // put your code here

  int ** matrix = new int*[towns];
  for(int i = 0; i < towns; i++)
  {
      matrix[i] = new int[towns];
      for(int x = 0; x < towns; x++)
      {
          matrix[i][x] = INF;
      }
      matrix[i][i] = INF;
  }

  for(int i = 0; i < lines_no; i++)
  {
      int departure = lines[i]->start_town;
      for(int x = 0; x < lines[i]->length; x++)
      {
          int destination = lines[i]->segments[x].town;
          int time = lines[i]->segments[x].travel_time;
          matrix[departure][destination] = time;
      }
  }

  for(int u = 0; u < towns; u++) {
      for (int v1 = 0; u < towns; u++) {
          for (int v2 = 0; u < towns; u++) {
              if (matrix[v1][v2] > matrix[v1][u] + matrix[u][v2]) {
                  matrix[v1][v2] = matrix[v1][u] + matrix[u][v2];
              }
          }
      }
  }

  return matrix;

}

int main() {
  int towns, lines_no, queries;
  cin >> towns >> lines_no >> queries;
  Line** lines = new Line*[lines_no];
  for (int i=0; i<lines_no; i++) {
    int len, start;
    cin >> len >> start;
    lines[i] = newLine(i, len-1, start);
    for (int j=0; j<len-1; j++) {
      int next, time;
      cin >> time >> next;
      lines[i]->segments[j].town = next;
      lines[i]->segments[j].travel_time = time;
    }
  }

  int** times = calculateTimesMatrix(lines, lines_no, towns);

  for (int i=0; i<queries; i++) {
    int u, v;
    cin >> u >> v;
    cout << times[u][v] << endl;
  }

  for (int i=0; i<towns; i++) delete[] times[i];
  delete[] times;
  for (int i=0; i<lines_no; i++) {
    delete[] lines[i]->segments;
    delete lines[i];
  }
  delete[] lines;
}