// Custom Includes
#include "grid.hpp"
#include "cell.hpp"
#include "textures.hpp"
#include "sizing.hpp"

// Basic
#include <iostream>
#include <vector>

// SFML
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

std::vector<std::vector<Cell>> grid;

void initializeGrid()
{
    grid.resize(GRID_HEIGHT);

    for (int x = 0; x < GRID_HEIGHT; x++)
    {
        grid[x].resize(GRID_WIDTH);
    }
}

void drawGrid(sf::RenderWindow &window)
{
    const float padding = 5.f;

    for (int row = 0; row < GRID_HEIGHT; row++)
    {
        for (int col = 0; col < GRID_WIDTH; col++)
        {
            Cell &cell = grid[row][col];

            sf::Sprite sprite = cell.getHidden();

            float posX = col * (TILE_WIDTH + padding);
            float posY = row * (TILE_HEIGHT + padding);
            sprite.setPosition(posX, posY);

            window.draw(sprite);
        }
    }
}

