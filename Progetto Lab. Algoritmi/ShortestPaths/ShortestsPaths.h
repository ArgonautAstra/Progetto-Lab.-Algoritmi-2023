//
// Created by Raffaele on 31/05/2023.
//

#ifndef PROGETTO_LAB_ALGORITMI_SHORTESTSPATHS_H
#define PROGETTO_LAB_ALGORITMI_SHORTESTSPATHS_H

#include "../FlightGraphs/FlightsGraph.h"
#include <utility>

class ShortestsPaths {
public:
    ShortestsPaths(FlightsGraph &g) : graph(g) {};
    std::pair<int, double> absoluteShortestPath();
private:
    FlightsGraph &graph;
};

#endif //PROGETTO_LAB_ALGORITMI_SHORTESTSPATHS_H
