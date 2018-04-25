#include <iostream>
using namespace std;

typedef struct point {
    int x, y;
} point;

typedef struct neighbours {
    int n;
    point elems[4];
} neighbours;

neighbours get_neighbours(int** labyrinth, int n, int m, point* p) {
    // find (if exist) all neighbours of point p
        // (consider points: one above p, one below p, one on the left site and one on the right site)
    // use defined structures
    neighbours result;
    result.n = 0;
    if(p->x > 0)
    {
        point out = {
            .x = p->x-1,
            .y = p->y
        };
        if(labyrinth[out.x][out.y] == 1)
        {
            result.elems[result.n] = out;
            result.n++;
        }
    }
    if(p->y > 0)
    {
        point out = {
            .x = p->x,
            .y = p->y-1
        };
        if(labyrinth[out.x][out.y] == 1)
        {
            result.elems[result.n] = out;
            result.n++;
        }
    }
    if(p->x < n-1)
    {
        point out = {
            .x = p->x+1,
            .y = p->y
        };
        if(labyrinth[out.x][out.y] == 1)
        {
            result.elems[result.n] = out;
            result.n++;
        }
    }
    if(p->y < m-1)
    {
        point out = {
            .x = p->x,
            .y = p->y+1
        };
        if(labyrinth[out.x][out.y] == 1)
        {
            result.elems[result.n] = out;
            result.n++;
        }
    }

    return result;
}

bool dfs(int** graph, int n, int m, bool** visited, point p, point end) {
    // if p is already at the end - return true
    if(p.x == end.x && p.y == end.y)
        return true;

    // mark p visited
    visited[p.x][p.y] = true;

    // call recursively on every unvisited neighbour
    neighbours nghb = get_neighbours(graph, n, m, &p);
    for(int i = 0; i < nghb.n; i++)
    {
        if(!visited[nghb.elems[i].x][nghb.elems[i].y])
            if(dfs(graph, n, m, visited, nghb.elems[i], end))
                return true;
    }
    
    // if all calls finished fruitlessly - you didn't find exit
    return false;
}


int main() {
    int n, m;
    cin >> n;
    cin >> m;
    int **labyrinth = new int*[n];
    for(int i=0; i<n; i++) labyrinth[i] = new int[m];
    bool** visited = new bool*[n];
    for(int i=0; i<n; i++) visited[i] = new bool[m];
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> labyrinth[i][j];
        }
    }
    point start, end;
    cin >> start.x;
    cin >> start.y;
    cin >> end.x;
    cin >> end.y;
    cout << (dfs(labyrinth, n, m, visited, start, end) ? "TAK" : "NIE") << endl;
}