//
// Created by marco on 5/27/2023.
//
#include <iostream>
#include <string>
#include <map>
#include "../FlightGraphs/FlightsGraph.h"

#ifndef PROGETTO_LAB_ALGORITMI_PARSE_H
#define PROGETTO_LAB_ALGORITMI_PARSE_H

extern std::map<int,std::vector<int>> map;

std::vector<FlightsGraph> parseFileToGraph(std::ifstream& file);





#endif //PROGETTO_LAB_ALGORITMI_PARSE_H
