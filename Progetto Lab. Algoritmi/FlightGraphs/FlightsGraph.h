// 
// Created by Raffaele on 26/05/2023.
//

#ifndef PROGETTO_LAB_ALGORITMI_FLIGHTSGRAPH_H
#define PROGETTO_LAB_ALGORITMI_FLIGHTSGRAPH_H
#include <vector>
#include <string>
#include <list>
#include <algorithm>
#include <ostream>

#include "FlightsEdge.h"
#include "FlightsMatrix.h"

using std::vector;
using std::string;
using std::list;

class FlightsGraph {
public:
    explicit FlightsGraph(const vector<string> &cities);
    void addFlight(int departure, int destination, double cost);
    bool pointsTo(int departure, int destination);
    double costOf(int departure, int destination);
    void setFlightCost(int departure, int destination, double newCost);
    friend std::ostream &operator<<(std::ostream &os, const FlightsGraph &graph);
    vector<int> topologicalSort();
    bool hasCycle();

    FlightsMatrix toMatrix();

    const vector<list<FlightsEdge>> &getAdj() const;
    int getNumV() const;

private:
    bool isDag;
    vector<list<FlightsEdge>> adj;
    vector<string> cities;
    vector<double> q; //per alg. proposto
    vector<bool> marked;
    vector<bool> beingMarked;
    int numV;
    void dfs(int source);
};


#endif //PROGETTO_LAB_ALGORITMI_FLIGHTSGRAPH_H
