#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <memory> 

// Forward declaration of Edge class
class Edge;

class Node {
private:
    int nodeId;
    bool isNest;
    std::vector<std::shared_ptr<Edge>> edges;
    double food;
    bool nodeHasFood;




public:
    Node(int id, double foodProb, double minFoodAmount, double maxFoodAmount);
    int getID();
    void addEdge(std::shared_ptr<Edge> edge);
    const std::vector<std::shared_ptr<Edge>>& getEdges() const;
    bool isNestNode() const;
    void setNest();
    double getFood() const;
    void generateFood(double foodProb, double minFoodAmount, double maxFoodAmount);
    bool doesitHaveFood();
    void depleteFood(double amount); 
    void addFood(double amount);
    void spwanFood(double foodProb, double minFoodAmount, double maxFoodAmount);



    // Declarations for copy constructor and copy assignment operator
    Node(const Node& other); // Declaration of the copy constructor
    Node& operator=(const Node& other); // Declaration of the copy assignment operator

};

class Edge {
private:
    std::weak_ptr<Node> sourceNode; // Source node 
    std::weak_ptr<Node> targetNode; // Target node 
    double weight;

public:
    Edge(std::shared_ptr<Node> srcNode, std::shared_ptr<Node> tgtNode, double w = 1.0); // construct edge 
    
    std::shared_ptr<Node> getSourceNode() const; // get source node of edge 
    std::shared_ptr<Node> getTargetNode() const; // get target node of edge 
    double getWeight() const; // get weight of edge 
    void addWeight(int amount);
    void decreaseWeight(double amount);
};

#endif // GRAPH_HPP
