//
// Created by weiss on 01/06/23.
//

#ifndef PROGETTO_LAB_ALGORITMI_FLIGHTSMATRIX_H
#define PROGETTO_LAB_ALGORITMI_FLIGHTSMATRIX_H

//RAII

class FlightsMatrix {
public:
    FlightsMatrix(int numV);
    void addFlight(int departure, int destination, double cost);
    double getCostOf(int departure, int destination);
    int getV() const;

    ~FlightsMatrix();

private:
    int v;
    double **adjMatrix;
};


#endif //PROGETTO_LAB_ALGORITMI_FLIGHTSMATRIX_H
