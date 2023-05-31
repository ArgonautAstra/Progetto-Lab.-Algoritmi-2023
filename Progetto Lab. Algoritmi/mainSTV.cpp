#include <iostream>
#include <climits>
#include <cstdlib>

using namespace std;

#define V 100
#define INF INT_MAX

// A Dynamic programming based function to find the shortest path from u to v with exactly q edges.
int shortestPath(int graph[][V], int u, int v, int q) {
    // Table to be filled up using DP. The value sp[i][j][e] will store
    // weight of the shortest path from i to j with exactly q edges
    int A[V][V], B[V][V], sp[q+1];
    int x = 1;

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            A[i][j] = (graph[i][j] != INF) ? graph[i][j] : INF;

    for (int e = 2; e <= q; e++, x *= -1)
        if(x == 1) {
            B[0][0] = INF;
            for (int i = 0; i < V; i++)
                for (int j = 0; j < V; j++, B[i][j] = INF)
                    for (int k = 0; k < V; k++)
                        if (graph[i][k] != INF && k != i != j && A[k][j] != INF)
                            B[i][j] = min(B[i][j], graph[i][k] + A[k][j]);
            sp[e] = B[u][v];
        }else{
            A[0][0] = INF;
            for (int i = 0; i < V; i++)
                for (int j = 0; j < V; j++,A[i][j] = INF)
                    for (int a = 0; a < V; a++)
                        if (graph[i][a] != INF && a != i != j && B[a][j] != INF)
                            A[i][j] = min(A[i][j], graph[i][a] + B[a][j]);
            sp[e] = A[u][v];
        }

        for (int i = 2; i <= q; i++)
            cout << "Total cost of flight(" << i << ") is: " << sp[i] << "$" << endl;

    return 0;
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
                graph[i][j] = rand() % 100 + 1;

    graph[0][V-1] = INF;

    for(int i = 0; i < V; i++, cout <<  endl)
        for (int j = 0; j < V; j++)
            cout << graph[i][j] << "\t";

    cout <<  endl;

    shortestPath(graph, 0, V-1, V-1);

    return 0;
}