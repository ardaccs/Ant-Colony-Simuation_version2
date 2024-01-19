cmake_minimum_required(VERSION 3.13)
project(simulation)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

set(MAIN_SOURCES main.cpp ../src/graph.cpp ../src/utils.cpp ../src/environment.cpp ../src/ant.cpp ../src/simulation.cpp ../src/visualizer.cpp)

set(TEST_SOURCES ../tests/test.cpp ../src/graph.cpp ../src/utils.cpp ../src/environment.cpp ../src/ant.cpp ../src/visualizer.cpp)

add_executable(simulate ${MAIN_SOURCES})
add_executable(test_executable ${TEST_SOURCES})

# Link SFML libraries
target_link_libraries(simulate PRIVATE sfml-graphics)
target_link_libraries(test_executable PRIVATE sfml-graphics)

# Set C++ features
target_compile_features(simulate PRIVATE cxx_std_17)
target_compile_features(test_executable PRIVATE cxx_std_17)

# Include directories for SFML headers
target_include_directories(
    simulate
    PUBLIC
    ${CMAKE_SOURCE_DIR}/include
    ${SFML_SOURCE_DIR}/include # Include SFML headers
)

target_include_directories(
    test_executable
    PUBLIC
    ${CMAKE_SOURCE_DIR}/include
    ${SFML_SOURCE_DIR}/include # Include SFML headers
)

install(TARGETS simulate)
