// to implement still 

/*
TEST_CASE("Testing whether the environment is set up correctly for a 7x7 grid") {
    std::vector<std::vector<bool>> v_test = create_adjMatrix(7, 7);
    Environment TestEnvironment;
    TestEnvironment.create_grid(v_test);

    const auto& nodes = TestEnvironment.getNodes();

    // Assert that the number of nodes matches expectations for a 7x7 grid
    CHECK(nodes.size() == 49);

    // Check the edges for nodes in the same row
    for (int row = 0; row < 7; ++row) {
        for (int col = 0; col < 6; ++col) {
            INFO("Node " << (row * 7 + col) << " edges check");
            CHECK(nodes[row * 7 + col]->getEdges().size() == 1); // Expecting 1 edge (right connection)
        }
    }

    // Check the edges for nodes in the same column
    for (int col = 0; col < 7; ++col) {
        for (int row = 0; row < 6; ++row) {
            INFO("Node " << (row * 7 + col) << " edges check");
            CHECK(nodes[row * 7 + col]->getEdges().size() == 1); // Expecting 1 edge (downward connection)
        }
    }

    // Edge cases (nodes on the last row and last column)
    for (int col = 0; col < 7; ++col) {
        INFO("Node " << (6 * 7 + col) << " edges check");
        CHECK(nodes[6 * 7 + col]->getEdges().size() == 0); // Expecting no downward edge for the last row
    }
    for (int row = 0; row < 7; ++row) {
        INFO("Node " << (row * 7 + 6) << " edges check");
        CHECK(nodes[row * 7 + 6]->getEdges().size() == 0); // Expecting no rightward edge for the last column
    }
}

*/
