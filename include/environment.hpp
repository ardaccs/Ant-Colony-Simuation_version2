#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP

#include <vector>
#include <memory> 
#include "graph.hpp"
#include "utils.hpp" 
#include "graph.hpp"

class Node;
class Edge;

class Environment { 
private:
    std::vector<std::shared_ptr<Node>> nodes; 
public:
    Environment(); 
    ~Environment();  

    void create_grid(const std::vector<std::vector<bool>>& adjacencyMatrix, int nestId, double foodProb, double minFoodAmount, double maxFoodAmount); // create a grid with nodes and edges following adjacency matrix 

    const std::vector<std::shared_ptr<Node>>& getNodes() const; 

    void printNodes() const;


    std::shared_ptr<Node> getNodeById(int nodeId) const;

};

#endif


