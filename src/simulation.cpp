#include "simulation.hpp"
#include "utils.hpp"
#include "visualizer.hpp"
#include <mutex> 

std::mutex consoleMutex; // Declare a mutex for console output synchronization

void simulateAnts(std::vector<Ant>& ants, int nestId, int size, const std::vector<std::shared_ptr<Node>>& nodes, int numIterations, double depFood, double depWeight,  double takeamount, double depositWeight, double foodProb, double minFoodAmount, double maxFoodAmount) {
    double pre_food = nodes[nestId]->getFood();

    // Create an SFML window for visualization
    //sf::RenderWindow window(sf::VideoMode(800, 600), "Ant Simulation");

    for (int iteration = 0; iteration < numIterations; ++iteration) {
        std::vector<std::thread> threads;

        // Simulate movement for each ant in parallel using threads
        for (int i = 0; i < ants.size(); ++i) {
            threads.emplace_back([&ants, i, nestId, size, &nodes, takeamount, depositWeight]() {
                ants[i].move(nestId, takeamount, depositWeight, nodes);
            });
        }

        // Join all threads to synchronize and wait for their completion
        for (auto& thread : threads) {
            thread.join();
        }

        // Lock the mutex before printing to synchronize console output
        std::lock_guard<std::mutex> lock(consoleMutex);
        //window.clear();
        //drawPositionSFML(window, ants, size, nodes);
        //window.display(); // Display the updated content


        printPosition(ants, size, nodes);
        std::this_thread::sleep_for(std::chrono::milliseconds(600));

        updateEnv(nodes, depFood, depWeight, foodProb, minFoodAmount, maxFoodAmount); // nodes, decrease food amount, decrease weight amount

    }
    double post_food = nodes[nestId]->getFood();
    std::cout << " food before searching at nest: " << pre_food << ". food after searching:  " << post_food << std::endl;
}

