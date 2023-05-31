//
// Created by Raffaele on 26/05/2023.
//

#include "FlightsGraph.h"
#include <algorithm>

FlightsGraph::FlightsGraph(const vector<string> &cities) {
    numV = cities.size();
    this->cities = vector<string>(cities.begin(), cities.end());
    adj.resize(numV);
}

void FlightsGraph::addFlight(int departure, int destination, double cost) {
    adj[departure].emplace_front(destination, cost);
}

bool FlightsGraph::pointsTo(int departure, int destination) {
    if(departure >= 0 && departure <= numV && destination >=0 && destination <= numV ) {
        auto l = adj.at(departure);
        auto condition = [&destination] (FlightsEdge fl) {return fl.getArrivalVertex() == destination;};
        auto res = std::find_if(l.begin(), l.end(), condition);
        return res != l.end();
    }
    return false;
}

double FlightsGraph::costOf(int departure, int destination) {
    if (departure >= 0 && departure <= numV && destination >= 0 && destination <= numV) {
        auto l = adj.at(departure);
        auto condition = [&destination] (FlightsEdge fl) {return fl.getArrivalVertex() == destination;};
        auto res = std::find_if(l.begin(), l.end(), condition);
        if(res == l.end()) return 0;
        else return res->getCost();
    }
    return 0;
}

void FlightsGraph::setFlightCost(int departure, int destination, double newCost) {
    if(pointsTo(departure, destination)) {
        auto l = adj.at(departure);
        auto condition = [&destination] (FlightsEdge fl) {return fl.getArrivalVertex() == destination;};
        auto res = std::find_if(l.begin(), l.end(), condition);
        res->setCost(newCost);
    }

    //else throw..
}

std::ostream &operator<<(std::ostream &os, const FlightsGraph &graph) {
    os << "Flight Graph" << std::endl;
    os << "Number of cities: " << graph.numV << std::endl;
    for(int k = 0; k < graph.numV; k++) {
        for(auto arr : graph.adj[k]) {
            os << graph.cities[k] << " " << graph.cities[arr.getArrivalVertex()] << " " << arr.getCost() << std::endl;
        }
    }
    return os;
}



