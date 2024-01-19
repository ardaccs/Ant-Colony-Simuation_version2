#include "visualizer.hpp" // Header file containing necessary declarations
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <sstream>
#include "Ant.hpp" 
#include "graph.hpp" 
#include <iomanip> 


void runSFMLVisualization() {
    sf::RenderWindow window({1920u, 1080u}, "SFML Visualization");
    window.setFramerateLimit(144);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();

        // Creating a circle shape
        sf::CircleShape circle(50); // Radius of the circle: 50
        circle.setFillColor(sf::Color::Red); // Set circle color to red
        circle.setPosition(100, 100); // Position the circle at (100, 100) on the window

        window.draw(circle); // Draw the circle to the window

        window.display();
    }
}

// void drawPositionSFML(sf::RenderWindow& window, const std::vector<Ant>& ants, int grid_size, const std::vector<std::shared_ptr<Node> >& nodes) {
//     const int cellWidth = 40; // Adjust cell width for visualization

//     sf::Font font; // Load a font for text rendering (you can choose your own font)
//     if (!font.loadFromFile("arial.ttf")) { // Replace "arial.ttf" with the path to your font file
//         // Font loading failed
//         return;
//     }

//     sf::Text text;
//     text.setFont(font);
//     text.setCharacterSize(20);
//     text.setFillColor(sf::Color::White);

//     window.clear(); // Clear the window

//     for (int i = 0; i < grid_size; ++i) {
//         for (int j = 0; j < grid_size; ++j) {
//             bool antPresent = false;

//             for (const auto& ant : ants) {
//                 const std::shared_ptr<Node>& currentNode = ant.getCurrentNode();
//                 if (currentNode && currentNode->getID() == (i * grid_size + j)) {
//                     std::string displayText;
//                     if (ant.hasFood) {
//                         displayText = "A(f)"; // Ant carrying food
//                     } else {
//                         displayText = "A"; // Ant without food
//                     }

//                     text.setString(displayText);
//                     text.setPosition(j * cellWidth, i * cellWidth);
//                     window.draw(text);
//                     antPresent = true;
//                     break;
//                 }
//             }

//             if (!antPresent) {
//                 double foodAmount = nodes[(i * grid_size + j)]->getFood();
//                 std::ostringstream oss;
//                 oss << std::fixed << std::setprecision(2) << foodAmount;
//                 std::string formattedFood = oss.str();

//                 text.setString(formattedFood.substr(0, std::min(cellWidth, static_cast<int>(formattedFood.size()))));
//                 text.setPosition(j * cellWidth, i * cellWidth);
//                 window.draw(text);
//             }
//         }
//     }

//     window.display(); // Display the updated content
// }

