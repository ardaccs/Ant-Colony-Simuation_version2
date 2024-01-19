#include "graph.hpp"
#include <random> 
#include <chrono> 


// Node class methods implementation
Node::Node(int id, double foodProb, double minFoodAmount, double maxFoodAmount) : nodeId(id), isNest(false) {
    generateFood( foodProb, minFoodAmount, maxFoodAmount);
}

void Node::depleteFood(double amount) {
    if (!isNestNode()){
        if (food > amount){
            food = food - amount; 
        }
        else { 
            food = 0;
        }

    }

}

void Node::addFood(double amount) {
    food = food + amount; 
}

void Node::generateFood(double foodProb, double minFoodAmount, double maxFoodAmount) {
    // Initialize random number generator for food presence
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_real_distribution<double> foodPresence(0.0, 1.0);

    // Probability for a node to have food 
    double probabilityOfFood = foodProb; 

    // Determine if the node has food based on the probability
    if (foodPresence(generator) < probabilityOfFood) {
        std::uniform_real_distribution<double> foodQuantity(minFoodAmount, maxFoodAmount);
        food = foodQuantity(generator);
        nodeHasFood = true;
    } else {
        // Node doesn't have food 
        food = 0;
    }
}

void Node::spwanFood(double foodProb, double minFoodAmount, double maxFoodAmount) {
    // Initialize random number generator for food presence
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_real_distribution<double> dropfood(0.0, 1.0);

    // Determine if the node has food based on the probability
    if (dropfood(generator) < foodProb && !isNestNode()) {
        std::uniform_real_distribution<double> foodQuantity(minFoodAmount, maxFoodAmount);
        food = food + foodQuantity(generator);
        nodeHasFood = true;
    } 
}

void Node::addEdge(std::shared_ptr<Edge> edge) { 
    edges.push_back(edge);
}


double Node::getFood() const {
    return food;
}

const std::vector<std::shared_ptr<Edge>>& Node::getEdges() const {
    return edges;
}

bool Node::doesitHaveFood() {
    return nodeHasFood;
}

bool Node::isNestNode() const {
    return isNest;
}

int Node::getID() {
    return nodeId;
}

void Node::setNest() {
    isNest = true;
    food = 0;
}

Node::Node(const Node& other) 
    : nodeId(other.nodeId), isNest(other.isNest), edges(other.edges) {}

Node& Node::operator=(const Node& other) {
    if (this != &other) { 
        nodeId = other.nodeId;
        isNest = other.isNest;
        edges = other.edges; 
    }
    return *this;
}

// Edge class methods implementation
Edge::Edge(std::shared_ptr<Node> srcNode, std::shared_ptr<Node> tgtNode, double w)
    : sourceNode(srcNode), targetNode(tgtNode), weight(w) {
}



std::shared_ptr<Node> Edge::getSourceNode() const {
    return sourceNode.lock(); 
}

std::shared_ptr<Node> Edge::getTargetNode() const {
    return targetNode.lock(); 
}

double Edge::getWeight() const {
    return weight;
}

void Edge::addWeight(int amount){
    weight = weight + amount;

}


void Edge::decreaseWeight(double amount) {
    if (weight >= amount) {
        weight -= amount; 
    } else {
        weight = 0;
    }
}