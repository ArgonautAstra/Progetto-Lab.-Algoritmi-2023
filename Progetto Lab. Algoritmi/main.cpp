#include <iostream>
#include <vector>
#include <fstream>
#include "FlightGraphs/FlightsGraph.h"
#include "parse/parse.h"
#include "PathsManager//PathsManager.h"
#include "Data Structures/IndexMinPQ.h"

#define V 10
#define INF INT_MAX

// A Dynamic programming based function to find the shortest path from u to v with exactly q edges.
int* shortestPath(int graph[V][V], int u, int v, int q) {
    int A[V][V], B[V][V], sp[q+1], i, j, k, e;
    unsigned char x = 1;

    for (i = 0; i < V; i++)
        for ( j = 0; j < V; j++)
            A[i][j] = (graph[i][j] != INF) ? graph[i][j] : INF;

    for (e = 2; e <= q; e++, x *= -1)
        for (i = 0; i < V; i++)
            for (j = 0, A[i][0] = INF, B[i][0] = INF; j < V; j++, A[i][j] = INF, B[i][j] = INF)
                for (k = 0; k < V; k++)
                    if (x == 1) {
                        if (graph[i][k] != INF && k != i != j && A[k][j] != INF)
                            B[i][j] = std::min(B[i][j], graph[i][k] + A[k][j]);
                        sp[e] = B[u][v];
                    } else {
                        if (graph[i][k] != INF && k != i != j && B[k][j] != INF)
                            A[i][j] = std::min(A[i][j], graph[i][k] + B[k][j]);
                        sp[e] = A[u][v];
                    }

    for (i = 2; i <= q; i++)
        std::cout << "Total cost of flight(" << i << ") is: " << sp[i] << "$" << std::endl;

    return sp;
}




int main(){
    std::ifstream file("text.txt");
    auto graphs = parseFileToGraph(file);
//    for (const auto& vec: graphs) {
//        std::cout << vec << std::endl;
//    }
//
//    for (const auto& pair: map) {
//
//        std::cout << "Scenarios: "<< pair.first << std::endl;
//        std::cout << "Numbers of query to calculate: " << std::endl;
//        if (pair.second.empty()) std::cout << "the vector is empty" << std::endl;
//        else {
//            for (auto a: pair.second) {
//
//                std::cout << a << " ";
//            }
//            std::cout << std::endl;
//        }
//        std::cout << std::endl;
//
//    }
    for (auto [scenarios, query]: map) {
        if (query.empty()){
            std::cout << "No Flights" << std::endl;
            continue;
        }
        auto graph = graphs[scenarios];
        auto pathsManager = PathsManager(graph);
        if (!graph.hasCycle())
            auto [vertices,cost] = pathsManager.absoluteShortestPathDag();
        else
            auto [vertices,cost] = pathsManager.absoluteShortestPath();
        
        auto min = pathsManager.shortestDistanceToNy();
        // Delete no bueno queries
        for(int i = 0; i < query.size(); i++) {
            auto k = query.at(i);
            if (k < min) query.erase(query.begin() + i);
        }
        auto max = query[query.size()-1];

        shortestPath(graph.toMatrix(),0,V-1,max);
        
        
        
        
            
    }


//    std::vector<std::string> cities;
//    cities.emplace_back("Palermo");
//    cities.emplace_back("2");
//    cities.emplace_back("3");
//    cities.emplace_back("4");
//    cities.emplace_back("5");
//    cities.emplace_back("New York");
//
//    FlightsGraph g(cities);
//
//    g.addFlight(0, 1, 1);
//    g.addFlight(0, 2, 1);
//    g.addFlight(1, 2, 4);
//    g.addFlight(2, 3, 2);
//    g.addFlight(2, 5, 7);
//    g.addFlight(3, 4, 2);
//    g.addFlight(3, 5, 1);
//    g.addFlight(4, 5, 1);
//
//    PathsManager sps(g);
//    auto sp = sps.absoluteShortestPathDag();
//    auto lp = sps.absoluteLongestPathDag();
//
//    std::cout << sp.first << " " << sp.second << std::endl;
//
//    std::cout << lp.first << " " << lp.second << std::endl;
//
//    //g.addFlight(3, 1, 2928);
//    std::cout << g.hasCycle() << std::endl;
//    auto spdk = sps.absoluteShortestPath();
//
//    std::cout << spdk.first << " " << spdk.second << std::endl;
//
//    auto testm = g.toMatrix();
//
//    for(int i = 0; i < testm.getV(); i++){
//        for(int j = 0; j < testm.getV(); j++) {
//            std::cout << testm.getCostOf(i, j) << " ";
//        }
//
//        std::cout << std::endl;
//    }
}