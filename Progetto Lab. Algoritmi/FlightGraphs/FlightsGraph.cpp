//
// Created by Raffaele on 26/05/2023.
//
#include <stack>
#include <queue>
#include "FlightsGraph.h"
#include <float.h>
#include <iostream>
#include <utility>

FlightsGraph::FlightsGraph(const vector<string> &cities) {
    numV = cities.size();
    this->cities = vector<string>(cities.begin(), cities.end());
    adj.resize(numV);
}

const vector<list<FlightsEdge>> &FlightsGraph::getAdj() const {
    return adj;
}

int FlightsGraph::getNumV() const {
    return numV;
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

vector<int> FlightsGraph::topologicalSort() {
    //si assume che il grafo sia un DAG
    vector<int> inDregrees(numV);
    vector<int> topologicalSort(numV);
    std::queue<int> zeros; // si può evitare risparmiando O(n) spazio

    int j = 0;

    //inizializzazione: calcola gli in-degrees di ogni nodo
    for(int i = 0; i < numV; i++) {
        auto l = adj[i];

        for(auto w : l) {
            inDregrees[w.getArrivalVertex()]++;
        }
    }

    //trova il primo nodo con in-degree 0
    for(int k = 0; k < numV; k++) {
        if(inDregrees[k] == 0) {
            zeros.push(k);
        }
    }


    while(!zeros.empty())
    {
        int v = zeros.front();
        zeros.pop();
        topologicalSort[j++] = v;

        //aggiorna la tabella
        auto l = adj[v];

        for(auto w : l){
            inDregrees[w.getArrivalVertex()]--;
            if(inDregrees[w.getArrivalVertex()] == 0){
                zeros.push(w.getArrivalVertex());
            }
        }
    }

    return topologicalSort;

}

bool FlightsGraph::hasCycle() {
    isDag = true;
    marked = vector<bool>(numV);
    beingMarked = vector<bool>(numV);
    dfs(0);
    return !isDag;
}

void FlightsGraph::dfs(int source) {
    beingMarked[source] = true;
    auto edges = adj.at(source);

    //pre-order

    for(auto edge : edges) {
        int w = edge.getArrivalVertex();
        if(beingMarked[w]) isDag = false;
        else if(!marked[w]) dfs(w);
    }
    beingMarked[source] = false;
    marked[source] = true;
}
