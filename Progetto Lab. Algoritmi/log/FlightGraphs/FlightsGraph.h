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

using std::vector;
using std::string;
using std::list;

class FlightsGraph {
public:
    explicit FlightsGraph(const vector<string> &cities);
    void addFlight(int departure, int destination, double cost);
    bool pointsTo(int departure, int destination);
    double costOf(int departure, int destination);

    friend std::ostream &operator<<(std::ostream &os, const FlightsGraph &graph);
    //void executeQuery(const vector<int> &queries);
private:
    vector<list<FlightsEdge>> adj;
    vector<string> cities;
    vector<double> q; //per alg. proposto
    vector<bool> marked;
    int numV;

    //void executeQueryUtil(int start, int i, double cost);
};


#endif //PROGETTO_LAB_ALGORITMI_FLIGHTSGRAPH_H
