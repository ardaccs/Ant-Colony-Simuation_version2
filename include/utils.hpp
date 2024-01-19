#ifndef UTILS_HPP
#define UTILS_HPP

#include <vector>
#include <iostream>
#include "ant.hpp"


std::vector<std::vector<bool>> create_adjMatrix(int numRows, int numCols);

// Function to print the adjacency matrix
void printAdjacencyMatrix(const std::vector<std::vector<bool>>& adjacencyMatrix);

void printPosition(const std::vector<Ant>& ants, int grid_size, const std::vector<std::shared_ptr<Node>>& nodes);

void updateEnv(std::vector<std::shared_ptr<Node> > nodes, double depFood, double depWeight, double foodProb, double minFoodAmount, double maxFoodAmount);


#endif
