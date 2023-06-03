//
// Created by Raffaele on 31/05/2023.
//

#ifndef PROGETTO_LAB_ALGORITMI_PATHSMANAGER_H
#define PROGETTO_LAB_ALGORITMI_PATHSMANAGER_H

#include "../FlightGraphs/FlightsGraph.h"
#include <utility>

class PathsManager {
public:
    PathsManager(FlightsGraph &g) : graph(g) {};
    std::pair<int, double> absoluteShortestPathDag();
    std::pair<int, double> absoluteShortestPath();
    int shortestDistanceToNy();
private:
    FlightsGraph &graph;
    void relax(int v, FlightsEdge edge, int edgeTo[], double distTo[]);
};

#endif //PROGETTO_LAB_ALGORITMI_PATHSMANAGER_H
