//
// Created by Raffaele on 31/05/2023.
//

#include <cfloat>
#include "PathsManager.h"
#include "../Data Structures/IndexMinPQ.h"
#include <queue>
#include <iostream>

std::pair<int, double> PathsManager::absoluteShortestPathDag() {
    auto tp = graph.topologicalSort();
    int numV = graph.getNumV();
    auto adj = graph.getAdj();
    double distTo[numV];
    int edgeTo[numV];

    for(int i = 0; i < numV; i++) {
        edgeTo[i] = -1;
        distTo[i] = DBL_MAX;
    }

    distTo[0] = 0;

    //calcola shortest path
    for(int v : tp) {
        for (auto edge: adj[v]) {
            relax(v, edge, edgeTo, distTo);
        }
    }

    std::pair<int, double> res;
    res.second = distTo[numV-1];

    int count = 0;
    for(int x = numV-1; x != 0; x = edgeTo[x]) {
        count++;
    }

    //numero di scali = numero di nodi tra Palermo e New York
    res.first = count - 1;
    return res;
}


void PathsManager::relax(int v, FlightsEdge edge, int *edgeTo, double *distTo) {
    int w = edge.getArrivalVertex();

    if(distTo[w] > distTo[v] + edge.getCost()) {
        distTo[w] = distTo[v] + edge.getCost();
        edgeTo[w] = v;
    }
}

//Algoritmo di Dijkstra
std::pair<int, double> PathsManager::absoluteShortestPath() {
    int numV = graph.getNumV();
    auto adj = graph.getAdj();
    double distTo[numV];
    int edgeTo[numV];

    for(int i = 0; i < numV; i++) {
        edgeTo[i] = -1;
        distTo[i] = DBL_MAX;
    }

    distTo[0] = 0;

    IndexMinPQ pq(numV);
    pq.insert(0, distTo[0]);

    while(!pq.isEmpty()) {
        int v = pq.deleteMin();

        for(auto edge : adj[v]) {
            int w = edge.getArrivalVertex();

            //passo di rilassamento
            if(distTo[w] > distTo[v] + edge.getCost()) {
                distTo[w] = distTo[v] + edge.getCost();
                edgeTo[w] = v;

                if(pq.contains(w)) {
                    pq.decreaseKey(w, distTo[w]);
                } else {
                    pq.insert(w, distTo[w]);
                }
            }
        }
    }
    std::pair<int, double> res;
    res.second = distTo[numV-1];

    int count = 0;
    for(int x = numV-1; x != 0; x = edgeTo[x]) {
        count++;
    }

    //numero di scali = numero di nodi tra Palermo e New York
    res.first = count - 1;
    return res;
}

int PathsManager::shortestDistanceToNy() {
    std::queue<int> q;
    auto adj = graph.getAdj();
    vector<bool> marked(graph.getNumV());
    vector<int> distTo(graph.getNumV());

    std::fill(distTo.begin(), distTo.end(),INT32_MAX);
    distTo[0] = 0;

    q.push(0);

    while(!q.empty()) {
        int v = q.front();
        q.pop();
        marked[v] = true;

        for(auto edge : adj.at(v)) {
            int w = edge.getArrivalVertex();

            if(!marked[w]) {
                distTo[w] = distTo[v]+1;
                marked[w] = true;
                q.push(w);
            }
        }
    }

    //scali = vertici tra palermo e new york
    return distTo[graph.getNumV()-1] - 1;
}

std::vector<double> PathsManager::shortestPathWithinK(int query) {
    int numV = graph.getNumV();
    std::vector<double> queries(query+1);
    auto adjMatrix = graph.toMatrix();

    double A[numV][numV], B[numV][numV], sp[query+1];
    int i, j, k, e;
    unsigned char x = 1;

    for (i = 0; i < numV; i++) {
        for (j = 0; j < numV; j++) {
            double cost = adjMatrix.getCostOf(i, j);
            A[i][j] = cost != DBL_MAX ? cost : DBL_MAX;
            B[i][j] = cost != DBL_MAX ? cost : DBL_MAX;
        }
    }

    for (e = 2; e <= query; e++, x *= -1) {
        for (i = 0; i < numV; i++) {
            for (j = 0, A[i][0] = DBL_MAX, B[i][0] = DBL_MAX; j < numV; j++, A[i][j] = DBL_MAX, B[i][j] = DBL_MAX) {
                for (k = 0; k < numV; k++) {
                    double cost = adjMatrix.getCostOf(i, k);
                    if (x == 1) {
                        if (cost != DBL_MAX && k != i != j && A[k][j] != DBL_MAX)
                            B[i][j] = std::min(B[i][j], cost + A[k][j]);
                        queries[e] = B[0][numV-1]; //TODO: queries[e-1] per numero vertici ?
                    } else {
                        if (cost != DBL_MAX && k != i != j && B[k][j] != DBL_MAX)
                            A[i][j] = std::min(A[i][j], cost + B[k][j]);
                        queries[e] = A[0][numV-1];
                    }
                }
            }
        }
    }

    return queries;
}
