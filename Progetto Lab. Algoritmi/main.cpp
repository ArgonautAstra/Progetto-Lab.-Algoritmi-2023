#include <iostream>
#include <vector>
#include <fstream>
#include "FlightGraphs/FlightsGraph.h"
#include "parse/parse.h"
#include "PathsManager//PathsManager.h"

int main(){
//    std::vector<std::string> cities;
//    cities.emplace_back("Palermo");
//    cities.emplace_back("Roma");
//    cities.emplace_back("Madrid");
//    cities.emplace_back("New York");
//
//    FlightsGraph g(cities);
//    g.addFlight(0, 1, 1);
//    g.addFlight(1, 2, 8);
//    g.addFlight(1, 3, 2);
//    g.addFlight(2, 3, 11);

/*
    std::ifstream file("text.txt");
    auto g = parseFileToGraph(file);
    for (auto vec: g) {
        std::cout << vec << std::endl;
    }

    for (auto pair: map) {

        std::cout << pair.first << std::endl;
        if (pair.second.empty()) std::cout << "the vector is empty" << std::endl;
        else {
            for (auto a: pair.second) {

                std::cout << a << " ";
            }
            std::cout << std::endl;
        }

    }
*/

    std::vector<std::string> cities;
    cities.emplace_back("Palermo");
    cities.emplace_back("2");
    cities.emplace_back("3");
    cities.emplace_back("4");
    cities.emplace_back("5");
    cities.emplace_back("New York");

    FlightsGraph g(cities);

    g.addFlight(0, 1, 1);
    g.addFlight(0, 2, 1);
    g.addFlight(1, 2, 4);
    g.addFlight(2, 3, 2);
    g.addFlight(2, 5, 7);
    g.addFlight(3, 4, 2);
    g.addFlight(3, 5, 1);
    g.addFlight(4, 5, 1);

    PathsManager sps(g);
    auto sp = sps.absoluteShortestPathDag();
    auto lp = sps.absoluteLongestPathDag();

    std::cout << sp.first << " " << sp.second << std::endl;

    std::cout << lp.first << " " << lp.second << std::endl;


    //g.addFlight(3, 1, 2928);
    std::cout << g.hasCycle() << std::endl;
}