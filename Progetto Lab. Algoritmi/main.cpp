#include <iostream>
#include <vector>
#include <fstream>
#include "FlightGraphs/FlightsGraph.h"
#include "parse/parse.h"
#include "PathsManager//PathsManager.h"
#include "Data Structures/IndexMinPQ.h"

#define V 10
#define INF INT_MAX



int main(){
    std::ifstream file("Texts/text.txt");
    auto graphs = parseFileToGraph(file);
    for (auto [scenarios, query]: map) {
        std::cout << "Scenario #" << scenarios + 1 << std::endl;
        if (query.empty()){
            std::cout << "No Flights" << std::endl;
            continue;
        }
        auto graph = graphs[scenarios];
        auto pathsManager = PathsManager(graph);
        
        auto min = pathsManager.shortestDistanceToNy();
        std::cout << "Delete all routes minor then " << min << std::endl;
        // Delete no bueno queries
        for(int i = 0; i < query.size(); i++) {
            auto k = query.at(i);
            if (k < min) query.erase(query.begin() + i);
        }
        
        auto max = query[query.size()-1];
        auto sp = pathsManager.shortestPathWithinK(max+1);
        
        // inf 200 300 125 600 800
        // 0  1   2   3   4   5
        // 200 200 125 125 125
        double min_print = sp[1];
        for(int i = 2; i < sp.size(); i++) {
            min_print = std::min(sp[i], min_print);
            std::cout << "k=" << i-1 << " " << "Total cost of flight is: " << min_print << std::endl;
        }
        
        
            
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