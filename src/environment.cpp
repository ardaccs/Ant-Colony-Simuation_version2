#include "environment.hpp"
#include <iostream>


Environment::Environment() {}

Environment::~Environment() {
}

const std::vector<std::shared_ptr<Node>>& Environment::getNodes() const {
    return nodes;
}



void Environment::create_grid(const std::vector<std::vector<bool>>& adjacencyMatrix, int nestId, double foodProb, double minFoodAmount, double maxFoodAmount) { // create a grid graph of nodes and edges 
// corresponding to adjacency matrix 
    int numRows = adjacencyMatrix.size(); 
    int numCols = adjacencyMatrix[0].size();
    int numNodes = numRows;
    for (int i = 0; i < numNodes; ++i) {
        auto newNode = std::make_shared<Node>(i, foodProb, minFoodAmount, maxFoodAmount);
        nodes.push_back(newNode);
    }
    int node_number = 0;
    for (int row = 0; row < numRows; ++row) {
        for (int col = 0; col < numCols; ++col) {
            if (adjacencyMatrix[row][col]) {
                auto newEdge = std::make_shared<Edge>(nodes[node_number], nodes[col], 0);
                nodes[node_number]->addEdge(newEdge);
            }
        }
        node_number = node_number + 1;
    }
    nodes[nestId]->setNest();
}

std::shared_ptr<Node> Environment::getNodeById(int nodeId) const {
    for (const auto& node : nodes) {
        if (node->getID() == nodeId) {
            return node;
        }
    }
    return nullptr; 
}

void Environment::printNodes() const {
    std::cout << "Nodes in the environment:" << std::endl;
    for (const auto& node : nodes) {
        std::cout << "Node ID: " << node->getID() << std::endl;
    }
}

