// Textures
#include "cell.hpp"
#include "grid.hpp"
#include "textures.hpp"
#include "sizing.hpp"

// SFML
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

// Standard Output
#include <iostream>
#include <optional>

int main()
{
    sf::RenderWindow window(sf::VideoMode({SCREEN_WIDTH, SCREEN_HEIGHT}), "Minestormer", sf::Style::Default);

    if (!loadTextures())
    {
        return -1;
    }

    initializeGrid();

    float gridWidth = GRID_WIDTH * (TILE_WIDTH + PADDING) - PADDING;
    float gridHeight = GRID_HEIGHT * (TILE_HEIGHT + PADDING) - PADDING;

    sf::Vector2f containerPosition((window.getSize().x - gridWidth) / 2.f, (window.getSize().y - gridHeight) / 2.f);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear(sf::Color(127, 127, 127));

        drawGrid(window);

        window.display();
    }

    return 0;
}