// Textures
#include "cell.hpp"
#include "grid.hpp"
#include "textures.hpp"
#include "sizing.hpp"
#include "generation.hpp"

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
    SCALE_FACTOR = 1.0f;
    sf::RenderWindow window(sf::VideoMode({SCREEN_WIDTH, SCREEN_HEIGHT}), "Minestormer", sf::Style::Close);
    window.setFramerateLimit(60);

    if (!loadTextures())
    {
        return -1;
    }

    sf::Vector2u windowSize = window.getSize();

    float availableWidth = windowSize.x;
    float availableHeight = windowSize.y;

    float unitWidth = TILE_SIZE + PADDING;
    float unitHeight = TILE_SIZE + PADDING;

    float scaleX = availableWidth / (GRID_WIDTH * unitWidth);
    float scaleY = availableHeight / (GRID_HEIGHT * unitHeight);

    SCALE_FACTOR = std::min(scaleX, scaleY);

    initializeGrid();
    generateGrid();

    while (window.isOpen())
    {
        sf::Event event;
        
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed && (event.mouseButton.button == sf::Mouse::Left || event.mouseButton.button == sf::Mouse::Right))
            {
                sf::Vector2i mousePixel = sf::Mouse::getPosition(window);
                sf::Vector2f mouseWorld = window.mapPixelToCoords(mousePixel);
            
                float totalWidth = GRID_WIDTH * (TILE_SIZE * SCALE_FACTOR + PADDING * SCALE_FACTOR) - (PADDING * SCALE_FACTOR);
                float totalHeight = GRID_HEIGHT * (TILE_SIZE * SCALE_FACTOR + PADDING * SCALE_FACTOR) - (PADDING * SCALE_FACTOR);
            
                float offsetX = (window.getSize().x - totalWidth) / 2.0f;
                float offsetY = (window.getSize().y - totalHeight) / 2.0f;
            
                int col = static_cast<int>((mouseWorld.x - offsetX) / ((TILE_SIZE + PADDING) * SCALE_FACTOR));
                int row = static_cast<int>((mouseWorld.y - offsetY) / ((TILE_SIZE + PADDING) * SCALE_FACTOR));
            
                if (row < 0 || row >= GRID_HEIGHT || col < 0 || col >= GRID_WIDTH)
                    continue;
            
                Cell& selected = grid[row][col];
            
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    if (!selected.getRevealed() && !selected.getFlagged())
                    {
                        selected.revealTile();
                    }
                }
            
                if (event.mouseButton.button == sf::Mouse::Right)
                {
                    if (!selected.getRevealed())
                    {
                        if (!selected.getFlagged())
                            selected.flagTile();
                        else
                            selected.unflagTile();
                    }
                }
            }            
        }

        window.clear(sf::Color(127, 127, 127));

        drawGrid(window);

        window.display();
    }

    return 0;
}