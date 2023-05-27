#include <iostream>
#include "FlightGraphs/FlightsGraph.h"
#include <string>
int main(){
    //FlightGraph test

    vector<string> cities;
    cities.emplace_back("Palermo");
    cities.emplace_back("Roma");
    cities.emplace_back("Madrid");
    cities.emplace_back("New York");

    FlightsGraph g(cities);
    g.addFlight(0, 1, 1);
    g.addFlight(1, 2, 8);
    g.addFlight(1, 3, 2);
    g.addFlight(2, 3, 11);

    /*
    std::cout << g.costOf(2, 3) << std::endl;
    std::cout << g.pointsTo(2, 3) << std::endl;
    */
    std::cout << g;
}