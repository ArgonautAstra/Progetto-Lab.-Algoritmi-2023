//
// Created by marco on 5/27/2023.
//
#include <fstream>
#include "parse.h"
#include "../FlightGraphs/FlightsGraph.h"
#include <stdexcept>
#include <iostream>
#include <regex>
#include <cstdio>

std::vector<std::string> split(const string& input, const string& regex) {
    // passing -1 as the submatch index parameter performs splitting
    std::regex re(regex);
    std::sregex_token_iterator
            first{input.begin(), input.end(), re, -1},
            last;
    return {first, last};
}

int atPos(const std::vector<std::string>& vec, const std::string& string){
    auto item = std::find(vec.begin(),vec.end(), string);
    return std::distance(vec.begin(),item);
}



std::unordered_map<int,std::vector<int>> map;



std::vector<FlightsGraph> parseFileToGraph(std::ifstream& file) {
    std::vector<FlightsGraph> graphs;
    
    if (!file.is_open()) {
        throw std::runtime_error("Error when reading file");
    }
    
    std::string line;
    std::getline(file,line);
    int scenarios = std::stoi(line);
    std::getline(file,line);
    for (int i = 0; i < scenarios && !file.eof(); i++) {
        int n_cities, n_flights;
        std::vector<std::string> cities;
        std::getline(file,line);
        n_cities = std::stoi(line);
        for (int j = 0; j < n_cities; j++) {
            std::getline(file,line);
            cities.emplace_back(line);
        }
        
        FlightsGraph graph(cities);
        std::getline(file,line);
        n_flights = std::stoi(line);
        
        int departure,destination;
        double cost;

        for (int j = 0; j < n_flights; j++) {
            std::getline(file,line);
            auto flights = split(line, " ");
            departure = atPos(cities,flights[0]);
            destination = atPos(cities, flights[1]);
            cost = std::stod(flights[2]);

            if (graph.pointsTo(departure,destination)) {
                if (graph.costOf(departure, destination) > cost) graph.setFlightCost(departure, destination, cost);
                continue;
            }
            if (departure == 0 && destination == cities.size()-1) continue;
            graph.addFlight(departure,destination,cost);
        }
        graphs.emplace_back(graph);

        std::getline(file,line);

        line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
        if (line.size() >= 2){
            line.pop_back();
            line.pop_back();
        }
        //std::cout << line<< std::endl;
        std::vector<int> query;
        for (int j = 0, k=2; j < line.size(); j++,k++) {
            query.push_back(k);
        }
        
        
        map[i] = query;
        
        std::getline(file,line);
        

    }
    return graphs;
}
    


