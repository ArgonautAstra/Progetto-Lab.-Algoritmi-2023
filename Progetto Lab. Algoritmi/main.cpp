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

        //Cancella le query non valide
        for(int i = 0; i < query.size(); i++) {
            auto k = query.at(i);
            if (k < min || k > graph.getNumV()-2){
                query.erase(query.begin() + i);
                std::cout << "Query " << k << " invalid: no flights" << std::endl;
            }
        }
        
        auto max = query[query.size()-1];
        auto sp = pathsManager.shortestPathWithinK(max+1);
        
        double minCost = sp[1];

        for(int i = 2, k = 0; i < sp.size(); i++, k++) {
            minCost = std::min(sp[i], minCost);
            if(query[k] == i-1) {
                std::cout << "Query" << query[k] << ": total cost of flight is: " << minCost << std::endl;
            }
        }

        std::cout << std::endl;
    }
}