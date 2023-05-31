#include <iostream>
#include <climits>
#include <cstdlib>

using namespace std;

#define V 10
#define INF INT_MAX

// A Dynamic programming based function to find the shortest path from u to v with exactly q edges.
int* shortestPath(int graph[][V], int u, int v, int q) {
    int A[V][V], B[V][V], sp[q+1], i, j, k, e;
    short int x = 1;

    for (i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            A[i][j] = (graph[i][j] != INF) ? graph[i][j] : INF;

    for (e = 2; e <= q; e++, x *= -1)
        for (i = 0; i < V; i++)
            for (j = 0, A[i][0] = INF, B[i][0] = INF; j < V; j++, A[i][j] = INF, B[i][j] = INF)
                for (k = 0; k < V; k++)
                    if (x == 1) {
                        if (graph[i][k] != INF && k != i != j && A[k][j] != INF)
                            B[i][j] = min(B[i][j], graph[i][k] + A[k][j]);
                        sp[e] = B[u][v];
                    } else {
                        if (graph[i][k] != INF && k != i != j && B[k][j] != INF)
                            A[i][j] = min(A[i][j], graph[i][k] + B[k][j]);
                        sp[e] = A[u][v];
                    }

    for (int i = 2; i <= q; i++)
        cout << "Total cost of flight(" << i << ") is: " << sp[i] << "$" << endl;

    return sp;
}

int main(){
    /*
    int graph[V][V] = {{INF, 1,3,5,INF},
                        {INF, INF, 1,3,8},
                        {INF, 2, INF,3,2},
                        {INF, 7, 4, INF,1},
                        {INF, INF, INF,INF, INF}};
    */

    srand (time(NULL));

    int graph[V][V];

    for(int i = 0; i < V; i++)
        for(int j = 0; j < V; j++)
            graph[i][j] = INF;

    for(int i = 0; i < V-1; i++)
        for(int j = 1; j < V; j++)
            if(i != j)
                graph[i][j] = rand() % 9 + 1;

    graph[0][V-1] = INF;

    for(int i = 0; i < V; i++, cout <<  endl)
        for (int j = 0; j < V; j++)
            cout << graph[i][j] << "\t";

    cout <<  endl;

    shortestPath(graph, 0, V-1, V-1);

    return 0;
}