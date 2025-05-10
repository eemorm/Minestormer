// Custom Includes
#include "grid.hpp"
#include "cell.hpp"
#include "sizing.hpp"
#include "textures.hpp"

// Basic
#include <iostream>
#include <vector>

// SFML
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

std::vector<std::vector<Cell>> grid(GRID_HEIGHT, std::vector<Cell>(GRID_WIDTH));

void initializeGrid()
{
    for (int r = 0; r < GRID_HEIGHT; ++r)
    {
        for (int c = 0; c < GRID_WIDTH; ++c)
        {
            grid[r][c] = Cell();
            grid[r][c].setCoords(r, c);
        }
    }
}

void drawGrid(sf::RenderWindow &window)
{
    for (int row = 0; row < GRID_HEIGHT; row++)
    {
        for (int col = 0; col < GRID_WIDTH; col++)
        {
            float totalWidth = GRID_WIDTH * (TILE_SIZE * SCALE_FACTOR + PADDING * SCALE_FACTOR) - (PADDING * SCALE_FACTOR);
            float totalHeight = GRID_HEIGHT * (TILE_SIZE * SCALE_FACTOR + PADDING * SCALE_FACTOR) - (PADDING * SCALE_FACTOR);

            float offsetX = (window.getSize().x - totalWidth) / 2.0f;
            float offsetY = (window.getSize().y - totalHeight) / 2.0f;

            Cell &cell = grid[row][col];

            sf::Sprite sprite = cell.getSprite();

            sprite.setScale(SCALE_FACTOR, SCALE_FACTOR);

            float posX = offsetX + col * ((TILE_SIZE * SCALE_FACTOR) + (PADDING * SCALE_FACTOR));
            float posY = offsetY + row * ((TILE_SIZE * SCALE_FACTOR) + (PADDING * SCALE_FACTOR));

            sprite.setPosition(posX, posY);

            window.draw(sprite);
        }
    }
}

void revealEmptyCells(int row, int col)
{
    const int cardinal[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    const int diagonal[4][2] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

    for (const auto &dir : cardinal)
    {
        int newRow = row + dir[0];
        int newCol = col + dir[1];

        if (newRow >= 0 && newRow < GRID_HEIGHT && newCol >= 0 && newCol < GRID_WIDTH)
        {
            Cell &neighbor = grid[newRow][newCol];
            if (!neighbor.getRevealed() && !neighbor.getFlagged())
            {
                neighbor.revealTile();
            }
        }
    }

    for (const auto &dir : diagonal)
    {
        int newRow = row + dir[0];
        int newCol = col + dir[1];

        if (newRow >= 0 && newRow < GRID_HEIGHT && newCol >= 0 && newCol < GRID_WIDTH)
        {
            Cell &neighbor = grid[newRow][newCol];

            if (!neighbor.getRevealed() && !neighbor.getFlagged() && neighbor.getMinesAround() > 0)
            {
                neighbor.revealTile();
            }
        }
    }
}
