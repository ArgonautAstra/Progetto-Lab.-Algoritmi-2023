//
// Created by weiss on 01/06/23.
//

#include "FlightsMatrix.h"
#include <float.h>


FlightsMatrix::FlightsMatrix(int numV) {
    v = numV;

    adjMatrix = new double*[numV];

    for(int i = 0; i < numV; i++) {
        adjMatrix[i] = new double[numV];
    }

    //inizializzazione
    for(int i = 0; i < v; i++) {
        for(int j = 0; j < v; j++) {
            adjMatrix[i][j] = DBL_MAX;
        }
    }
}
FlightsMatrix::~FlightsMatrix() {
    for(int i = 0; i < v; i++) {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
}

void FlightsMatrix::addFlight(int departure, int destination, double cost) {
    if(departure >= 0 && departure < v && destination >= 0 && destination < v) {
        adjMatrix[departure][destination] = cost;
    }
}

double FlightsMatrix::getCostOf(int departure, int destination) {
    if(departure >= 0 && departure < v && destination >= 0 && destination < v) {
        return adjMatrix[departure][destination];
    }
    else return DBL_MAX;
}

int FlightsMatrix::getV() const {
    return v;
}
