//
// Created by Raffaele on 26/05/2023.
//

#ifndef PROGETTO_LAB_ALGORITMI_FLIGHTSEDGE_H
#define PROGETTO_LAB_ALGORITMI_FLIGHTSEDGE_H


class FlightsEdge {
public:
    FlightsEdge() {}
    FlightsEdge(int arrivalVertex, double cost) : arrivalVertex(arrivalVertex), cost(cost) {}

    int getArrivalVertex() const {
        return arrivalVertex;
    }

    double getCost() const {
        return cost;
    }

private:
    int arrivalVertex;
    double cost;
};


#endif //PROGETTO_LAB_ALGORITMI_FLIGHTSEDGE_H
