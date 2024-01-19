// Ant.cpp

#include "ant.hpp"
#include <cstdlib>
#include <iostream>
#include <chrono>
#include <thread>

int Ant::nextId = 1; 


Ant::Ant(const std::shared_ptr<Node>& currentNode)
    : _id(nextId++), currentNode(currentNode), hasFood(false) {
}

Ant::Ant() {
    _id = nextId++;
}

Ant::Ant(const Ant& other)
    : _id(nextId++), currentNode(other.currentNode), path(other.path), hasFood(other.hasFood) {
}

int Ant::getId() const {
    return _id; // Return the unique ID of the ant
}

Ant::~Ant() {}


// Definition of the copy assignment operator
Ant& Ant::operator=(const Ant& other) {
    if (this != &other) { // Self-assignment check
        _id = other._id;
        currentNode = other.currentNode;
        hasFood = other.hasFood;
    }
    return *this;
}

void Ant::takeFood(double amount){
    currentNode->depleteFood(amount);
    carriedFood = amount; 
    //std::cout << "Food taken by the ant: " << carriedFood << std::endl; // Add this line for debugging

}

void Ant::depositFood(int nestID) {
    currentNode->addFood(carriedFood);
    carriedFood = 0;
}



std::vector<std::shared_ptr<Edge>> Ant::getPath(){
    return path;
}

void Ant::addPath(std::shared_ptr<Edge> edge){
    path.push_back(edge);
}

void Ant::returnHome(int nestId, double depositWeight, const std::vector<std::shared_ptr<Node>>& nodes) {

    // Ensure there's a path to follow
    if (!path.empty()) {
        std::shared_ptr<Node> sourceNode = path.back()->getSourceNode();
        std::shared_ptr<Node> targetNode = path.back()->getTargetNode();

        dropPheremone(path.back(), depositWeight); 
        path.pop_back(); 

        // Check if the target node matches the current node
        if (targetNode->getID() == currentNode->getID()) {
            // Move to the source node
            currentNode = sourceNode;

            
        } else if (sourceNode->getID() == currentNode->getID()) {
            // Move to the target node
            currentNode = targetNode;
        }

        // Check if the ant has returned to the nest
        if (currentNode->getID() == nestId) {
            depositFood(nestId);
            hasFood = false; 
            path.clear(); 
        }
    }
}




void Ant::searchForFood(int takeamount, const std::vector<std::shared_ptr<Node>>& nodes) {
    int node_num = currentNode->getID();
    //std::cout << " Looking for food";

    // Print initial position
    //printPosition(node_num, size, nodes);

    const std::vector<std::shared_ptr<Edge>>& edges = currentNode->getEdges();
    //std::cout << " Looking for food. " << "food: " << currentNode->getFood() << " node ID: " << currentNode->getID() << std::endl; 

    if (!edges.empty()) {
        int maxWeight = 0;
        int edgeIndex = -1; 

        // Find the maximum weight among edges
        for (int edge = 0; edge < edges.size(); ++edge) {
            if (edges[edge]->getWeight() > maxWeight) {
                maxWeight = edges[edge]->getWeight();
                edgeIndex = edge;
            }
        }

        // If all weights are zero, choose a random edge
        if (maxWeight == 0) {
            edgeIndex = rand() % edges.size();
        }

        // Move to the next node
        currentNode = edges[edgeIndex]->getTargetNode();
        addPath(edges[edgeIndex]);
        node_num = currentNode->getID();


        // Check if the current node has food
        if (currentNode->getFood() > 0 && !currentNode->isNestNode()) {
            hasFood = true;
            currentNode->depleteFood(takeamount); 
            takeFood(takeamount);
        }
    }
}


void Ant::move(int nestId, double takeamount, double depositWeight, const std::vector<std::shared_ptr<Node>>& nodes) {
    // Check if the ant has food
    if (hasFood) {
        //std::cout << "ant " <<  _id <<  "has food " << hasFood << " at current position" << currentNode->getID() << "  returning home" << std::endl;
        returnHome(nestId,depositWeight,nodes);
    } else {
        //std::cout << "ant " <<  _id <<   "has food " << hasFood <<  " at current position" << currentNode->getID() <<  " searching for food " << std::endl;
        searchForFood(takeamount,nodes);

    } 

}


const std::shared_ptr<Node>& Ant::getCurrentNode() const {
    return currentNode;
}

void Ant::setCurrentNode(const std::shared_ptr<Node>& node) {
    currentNode = node;
}



void Ant::dropPheremone(std::shared_ptr<Edge>& edge, int pheremone) {
    edge->addWeight(1);
}