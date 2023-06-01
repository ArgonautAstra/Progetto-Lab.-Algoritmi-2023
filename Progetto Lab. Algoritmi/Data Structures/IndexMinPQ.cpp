//
// Created by weiss on 01/06/23.
//

#include "IndexMinPQ.h"

IndexMinPQ::IndexMinPQ(int maxElements) {
    maxNum = maxElements;
    num = 0;
    keys = vector<double>(maxNum+1);
    pq = vector<int>(maxNum+1);
    qp = vector<int>(maxNum+1);

    for(int i = 0; i<=maxNum; i++) {
        qp[i] = -1;
    }
}

void IndexMinPQ::insert(int index, double key) {
    num++;
    qp[index] = num;
    pq[num] = index;
    keys[index] = key;
    bubbleUp(num);
}

void IndexMinPQ::bubbleUp(int k) {
    while(k > 1 && keys[pq[k / 2]] > keys[pq[k]] ) {
        swap(k, k / 2);
        k = k / 2;
    }
}

void IndexMinPQ::bubbleDown(int k) {
    while(2 * k <= num) {
        int j = 2*k;
        if(j < num && keys[pq[j]]>keys[pq[j+1]]) {
            j++;
        }
        if(keys[pq[k]] <= keys[pq[j]]) break;
        swap(k, j);
        k = j;
    }
}

void IndexMinPQ::swap(int a, int b) {
    int tmp = pq[a];
    pq[a] = pq[b];
    pq[b] = tmp;

    qp[pq[a]] = a;
    qp[pq[b]] = b;
}

int IndexMinPQ::deleteMin() {
    int min = pq[1];
    swap(1, num--);
    bubbleDown(1);
    qp[min] = 1;
    pq[num+1] = -1;
    return min;
}

void IndexMinPQ::decreaseKey(int index, double key) {
    keys[index] = key;
    bubbleUp(qp[index]);
}

bool IndexMinPQ::contains(int i) {
    return qp[i] != -1;
}

bool IndexMinPQ::isEmpty() {
    return num == 0;
}

