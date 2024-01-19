// Ant.hpp

#ifndef ANT_HPP
#define ANT_HPP

#include <vector>
#include <memory>
#include "graph.hpp"

class Ant {
private:
    int _id;
    std::shared_ptr<Node> currentNode; 
    std::vector<std::shared_ptr<Edge>> path;
    static int nextId; 


public:
    bool hasFood;
    double carriedFood;

    Ant(); 
    Ant(const std::shared_ptr<Node>& currentNode); 
    Ant(const Ant& other); 
    Ant& operator=(const Ant& other);
    ~Ant(); 
    void move(int nestId, double takeamount, double depositWeight, const std::vector<std::shared_ptr<Node>>& nodes); 
    const std::shared_ptr<Node>& getCurrentNode() const; 
    void setCurrentNode(const std::shared_ptr<Node>& node); 
    void printPosition(int node_num, int grid_size, const std::vector<std::shared_ptr<Node>>& nodes);
    void addPath(const std::shared_ptr<Edge> edge); 
    std::vector<std::shared_ptr<Edge>> getPath(); 
    void searchForFood(int amount, const std::vector<std::shared_ptr<Node>>& nodes);
    void returnHome(int nestId, double depositWeight, const std::vector<std::shared_ptr<Node>>& nodes);
    void dropPheremone(std::shared_ptr<Edge>& edge, int pheremone);
    void depositFood(int nestID);
    int getId() const;
    void takeFood(double amount);
};

#endif
