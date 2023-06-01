project(Progetto_Lab.Algoritmi)
cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


add_executable(main main.cpp parse/parse.cpp parse/parse.h FlightGraphs/FlightsGraph.h FlightGraphs/FlightsGraph.cpp PathsManager/PathsManager.cpp PathsManager/PathsManager.h "Data Structures/IndexMinPQ.cpp")