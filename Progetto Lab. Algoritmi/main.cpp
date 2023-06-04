#include <iostream>
#include <vector>
#include <fstream>
#include "FlightGraphs/FlightsGraph.h"
#include "parse/parse.h"
#include "PathsManager//PathsManager.h"






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
        std::cout << "Deletes all routes minor then " << min << std::endl;
        // Deletes no bueno queries
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
    
}