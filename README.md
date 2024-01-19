# 84

to run go into build directory, run make, and then either ./simulation or ./test_executable for running the code or tests respectively. 

This code implements the basics of an ant colony simulation. defining the graph, the environment and the ant objects. it builds a graph structured like a nxn grid with an adjacency matrix. the ant then moves through 
the randomly around the grid searching for food, and when it finds food it returns home on the same path that it took to find food (here we will implement pheromone trails in the next sprint so that with multiple ants they will find the optimal route). A simple visualisation of the ant movement is included. 


**Sprint 1: Basic Simulation Setup**
In this initial sprint, we'll focus on setting up the fundamental elements of the simulation:

- Create a grid-based environment to represent the ant colony's habitat.
- Establish core simulated elements, including environment setup (resources, grid, etc.), and build a simple simulation loop.
- Establish core rule based mechanism for ant foraging. 
