
#include "../include/graph.hpp"
#include "../include/environment.hpp"
#include "../include/utils.hpp" 
#include "../include/ant.hpp"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN 
#include "doctest.h"



TEST_CASE("Testing whether the environment is set up correctly") {
    std::vector<std::vector<bool>> v_test = create_adjMatrix(3, 3);
    Environment TestEnvironment;
    TestEnvironment.create_grid(v_test, 3, 0.2, 1, 10);

    const auto& nodes = TestEnvironment.getNodes();

    // Assert that the number of nodes and edges matches expectations
    CHECK(nodes.size() == 9);

    for(int i = 1; i < 8; i=i+2){

        CHECK(nodes[i]->getEdges().size() == 3 /* expected number of edges for a en even numbered node made by 3x3 matrix */);
    }

    CHECK(nodes[4]->getEdges().size() == 4);

}


TEST_CASE("Testing adjacency matrix creation") {
    std::vector<std::vector<bool>> adjMatrix1 = create_adjMatrix(3, 3);
    // Check the structure of the generated adjacency matrix
    CHECK(adjMatrix1.size() == 9); // Ensure the matrix has 9 nodes
    CHECK(adjMatrix1[0][1]); // Check if node 0 is connected to node 1

    std::vector<std::vector<bool>> adjMatrix2 = create_adjMatrix(4, 4);
    // Check the structure of the generated adjacency matrix
    CHECK(adjMatrix2.size() == 16); // Ensure the matrix has 16 nodes
    CHECK(adjMatrix2[5][9]); // Check if node 5 is connected to node 9

    SUBCASE("Additional details for failure") {
        // Provide additional logging information for assertions
        INFO("Adjacency Matrix 1 Details:");
        INFO("Size: " << adjMatrix1.size());
        INFO("Node 0 to Node 1: " << adjMatrix1[0][1]);

        INFO("Adjacency Matrix 2 Details:");
        INFO("Size: " << adjMatrix2.size());
        INFO("Node 5 to Node 9: " << adjMatrix2[5][9]);
    }
}

TEST_CASE("Testing adjacency matrix creation 7x7") {
    std::vector<std::vector<bool>> adjMatrix = create_adjMatrix(7, 7);

    // Check the structure of the generated adjacency matrix
    CHECK(adjMatrix.size() == 49); // Ensure the matrix has 49 nodes

    // Check connections in the adjacency matrix for nodes in the same row
    for (int row = 0; row < 7; ++row) {
        for (int col = 0; col < 6; ++col) {
            INFO("Node " << (row * 7 + col) << " to Node " << (row * 7 + col + 1));
            CHECK(adjMatrix[row * 7 + col][row * 7 + col + 1]); // Check right connection
        }
    }

    // Check connections in the adjacency matrix for nodes in the same column
    for (int col = 0; col < 7; ++col) {
        for (int row = 0; row < 6; ++row) {
            INFO("Node " << (row * 7 + col) << " to Node " << ((row + 1) * 7 + col));
            CHECK(adjMatrix[row * 7 + col][(row + 1) * 7 + col]); // Check downward connection
        }
    }

    SUBCASE("Additional details for failure") {
        // Provide additional logging information for assertions
        INFO("Adjacency Matrix Details:");
        // Log details about the connections (can be omitted if not needed)
    }
}


