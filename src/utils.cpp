#include "utils.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>


std::vector<std::vector<bool>> create_adjMatrix(int numRows, int numCols) {
    int numNodes = numRows * numCols;
    std::vector<std::vector<bool>> adjacencyMatrix(numNodes, std::vector<bool>(numNodes, false));

    for (int row = 0; row < numRows; ++row) {
        for (int col = 0; col < numCols; ++col) {
            int currentNode = row * numCols + col;

            // Connect to the right
            if (col < numCols - 1) {
                int rightNode = currentNode + 1;
                adjacencyMatrix[currentNode][rightNode] = true;
                adjacencyMatrix[rightNode][currentNode] = true;
            }

            // Connect to the left
            if (col > 0) {
                int leftNode = currentNode - 1;
                adjacencyMatrix[currentNode][leftNode] = true;
                adjacencyMatrix[leftNode][currentNode] = true;
            }

            // Connect downward
            if (row < numRows - 1) {
                int downNode = currentNode + numCols;
                adjacencyMatrix[currentNode][downNode] = true;
                adjacencyMatrix[downNode][currentNode] = true;
            }

            // Connect upward
            if (row > 0) {
                int upNode = currentNode - numCols;
                adjacencyMatrix[currentNode][upNode] = true;
                adjacencyMatrix[upNode][currentNode] = true;
            }
        }
    }

    return adjacencyMatrix;
}

void updateEnv(std::vector<std::shared_ptr<Node> > nodes, double depFood, double depWeight, double foodProb, double minFoodAmount, double maxFoodAmount){
    for (int i = 0; i<nodes.size(); i++) {
        std::vector<std::shared_ptr<Edge>> edges = nodes[i]->getEdges();
        if (nodes[i]->doesitHaveFood()){
            nodes[i]->depleteFood(depFood); // deplete food at node by small amount 

            nodes[i] -> spwanFood(foodProb, minFoodAmount, maxFoodAmount);
        }
        for (int j = 0; j<edges.size(); j++){
            std::shared_ptr<Edge> edge = edges[j];
            edge->decreaseWeight(0.1);

        }
    }
}

void printAdjacencyMatrix(const std::vector<std::vector<bool>>& adjacencyMatrix) {
    for (const auto& row : adjacencyMatrix) {
        for (bool value : row) {
            std::cout << (value ? "1" : "0") << " "; 
        }
        std::cout << std::endl; 
    }
}

void printPosition(const std::vector<Ant>& ants, int grid_size, const std::vector<std::shared_ptr<Node>>& nodes) {
    std::cout << "\033[2J\033[H"; 

    const int cellWidth = 8; 

    for (int i = 0; i < grid_size; ++i) {
        for (int j = 0; j < grid_size; ++j) {
            bool antPresent = false;

            for (const auto& ant : ants) {
                const std::shared_ptr<Node>& currentNode = ant.getCurrentNode();
                if (currentNode && currentNode->getID() == (i * grid_size + j)) {
                    if (ant.hasFood) {
                        std::cout << std::setw(cellWidth) << std::right << "A(f)"; // Ant carrying food
                    } else {
                        std::cout << std::setw(cellWidth) << std::right << "A"; // Ant without food
                    }
                    antPresent = true;
                    break;
                }
            }

            // If no ant is present, print the node status or food amount
            if (!antPresent) {
                double foodAmount = nodes[(i * grid_size + j)]->getFood();
                std::ostringstream oss;
                oss << std::fixed << std::setprecision(2) << foodAmount;
                std::string formattedFood = oss.str();
                std::cout << std::setw(cellWidth) << std::right << formattedFood.substr(0, std::min(cellWidth, static_cast<int>(formattedFood.size()))); // Node with food or empty node
            }
        }
        std::cout << std::endl;
    }

    std::cout << std::flush; // Flush the output stream to ensure live update
}
