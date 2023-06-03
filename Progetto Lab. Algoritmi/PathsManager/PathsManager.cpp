//
// Created by Raffaele on 31/05/2023.
//

#include <cfloat>
#include "PathsManager.h"
#include "../Data Structures/IndexMinPQ.h"
#include <queue>

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
