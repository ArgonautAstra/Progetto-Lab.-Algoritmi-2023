//
// Created by weiss on 01/06/23.
//

#ifndef PROGETTO_LAB_ALGORITMI_INDEXMINPQ_H
#define PROGETTO_LAB_ALGORITMI_INDEXMINPQ_H

#include <vector>
#include "../Data Structures/IndexMinPQ.h"

using std::vector;

//Coda a priorità indicizzata, utilizzata nell'algoritmo di Dijkstra in PathsManager.cpp

class IndexMinPQ {
public:
    IndexMinPQ(int maxElements);
    void insert(int index, double key);
    int deleteMin();
    void decreaseKey(int index, double key);
    bool contains(int i);
    bool isEmpty();
private:
    int maxNum;
    int num;
    vector<int> pq;
    vector<int> qp;
    vector<double> keys;
    void swap(int a, int b);
    void bubbleUp(int k);
    void bubbleDown(int k);
};


#endif //PROGETTO_LAB_ALGORITMI_INDEXMINPQ_H
