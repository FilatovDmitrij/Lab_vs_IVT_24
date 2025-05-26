#include "Graph.h"
#include <iostream>
#include <SFML/Graphics.hpp>

void setupFont(sf::Font& font) {
    const std::string fontOptions[] = {
        "arial.ttf",
        "fonts/arial.ttf",
        "C:/Windows/Fonts/arial.ttf"
    };

    for (const auto& option : fontOptions) {
        if (font.loadFromFile(option)) {
            return;
        }
    }
    std::cerr << "Font loading failed\n";
}

void showResults(const std::vector<int>& breadthPath, 
                const std::vector<int>& depthPath,
                const std::map<int, int>& pathLengths) {
    std::cout << "Breadth exploration: ";
    for (int point : breadthPath) std::cout << point << " ";
    std::cout << "\nDepth exploration: ";
    for (int point : depthPath) std::cout << point << " ";
    
    std::cout << "\nPath distances:\n";
    for (const auto& path : pathLengths) {
        std::cout << "To point " << path.first << ": " << path.second << "\n";
    }
}

int main() {
    sf::Font displayFont;
    setupFont(displayFont);

    sf::RenderWindow displayWindow(sf::VideoMode(800, 600), "Graph Display");
    displayWindow.setFramerateLimit(60);

    Graph network(false);
    
    for (int i = 1; i <= 6; ++i) {
        network.includePoint(i);
    }

    network.establishLink(1, 2, 8);
    network.establishLink(1, 6, 11);
    network.establishLink(2, 3, 12);
    network.establishLink(2, 5, 10);
    network.establishLink(3, 4, 16);
    network.establishLink(5, 4, 5);
    network.establishLink(5, 6, 6);
    network.establishLink(4, 6, 9);

    auto breadthPath = network.exploreBreadth(6);
    auto depthPath = network.exploreDepth(6);
    auto pathLengths = network.calculatePaths(6);

    showResults(breadthPath, depthPath, pathLengths);

    while (displayWindow.isOpen()) {
        sf::Event interaction;
        while (displayWindow.pollEvent(interaction)) {
            if (interaction.type == sf::Event::Closed) {
                displayWindow.close();
            }
        }

        displayWindow.clear(sf::Color::White);
        network.display(displayWindow);
        displayWindow.display();
    }

    return 0;
}