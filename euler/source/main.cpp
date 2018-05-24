#include <stdio.h>
// we're big guys now, let's use already implemeted list
// you might want check this out: http://www.cplusplus.com/reference/list/list/#functions
#include <list>

using namespace std;

enum graph_type {
    EULER = 1,
    HALF = 2,
    NO = 3
};

graph_type check_graph(list<int> graph[], int n) {

    /**********************
    * Place for your code *
    **********************/
    int nieparzysty_stopien = 0;

    for(int i = 0; i<n; i++)
    {
        if(graph[i].size() % 2 != 0)
        {
            nieparzysty_stopien++;
        }
    }

    if (nieparzysty_stopien == 0) {
        return EULER;
    } else if (nieparzysty_stopien <= 2) {
        return HALF;
    } else {
        return NO;
    }
}

int main() {
    int Z;

    scanf("%d", &Z);

    while (Z--) {

        int n, m;
        int u, v;
        scanf("%d %d", &n, &m);
        list<int> *graph = new list<int>[n+1];
        for(int i=0; i<m; i++) {
            scanf("%d %d", &u, &v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        graph_type result = check_graph(graph, n);
        switch(result) {
            case EULER:
                printf("EULER\n");
                break;
            case HALF:
                printf("HALF\n");
                break;
            case NO:
                printf("NO\n");
                break;
        }
        delete [] graph;
    }
}
