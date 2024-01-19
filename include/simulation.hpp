#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include <vector>
#include <iostream>
#include "graph.hpp"
#include "ant.hpp"
#include <thread>


void simulateAnts(std::vector<Ant>& ants, int nestId, int size, const std::vector<std::shared_ptr<Node>>& nodes, int numIterations, double depFood, double depWeight,  double takeamount, double depositWeight, double foodProb, double minFoodAmount, double maxFoodAmount);


#endif