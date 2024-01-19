#include <vector>
#include <iostream>
#include "include/graph.hpp"
#include "include/environment.hpp"
#include "include/utils.hpp"
#include "include/ant.hpp"
#include "simulation.hpp"
#include "visualizer.hpp"
#include <thread>

int main() {
    runSFMLVisualization();
    
    // Control Parameters For The Simulation
    int size = 5;
    int nestId = 11;
    const int num_ants = 100; // Number of ants in the simulation
    const int numIterations = 100; // Number of iterations for the simulation
    double depFood = 0.01;  // depreciate food of node 
    double depWeight = 0.03; // depreciate weight of edge 
    double takeamount = 1; // amount of food the ant takes 
    double depositWeight = 1; // amount of pheremones an ant deposits 
    double foodProb = 0.3; // probability of node having food 
    double minFoodAmount = 1; // minimum amount of food at a node
    double maxFoodAmount = 10; // max amount of food at a node 
    double s_foodProb = 0.01; // spontaneously generate food
    double s_minFoodAmount = 1; // max spontaneous food 
    double s_maxFoodAmount = 10; // min spontaneous food 


    std::vector<std::vector<bool>> adj_matrix = create_adjMatrix(size, size);

    Environment theEnvironment;
    theEnvironment.create_grid(adj_matrix, nestId, foodProb, minFoodAmount, maxFoodAmount);

    const std::vector<std::shared_ptr<Node>>& nodes = theEnvironment.getNodes();

    std::vector<Ant> ants; // Vector to store multiple ants

    for (int i = 0; i < num_ants; ++i) {
        std::shared_ptr<Node> node = theEnvironment.getNodeById(nestId);
        if (node) {
            ants.emplace_back(node);
        } else {
            std::cout << "Node with ID " << nestId << " does not exist in the environment." << std::endl;
        }
    }

    simulateAnts(ants, nestId, size, nodes, numIterations, depFood, depWeight, takeamount, depositWeight, s_foodProb, s_minFoodAmount, s_maxFoodAmount);

    return 0;
}

