#include <iostream>
#include <vector>
#include <fstream>
#include "FlightGraphs/FlightsGraph.h"
#include "parse/parse.h"

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
}


