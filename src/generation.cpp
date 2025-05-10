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
#include <cstdlib>
#include <ctime> 

void generateGrid()
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // Place mines randomly
    for (int i = 0; i < NUM_MINES;)
    {
        int row = std::rand() % GRID_HEIGHT;
        int col = std::rand() % GRID_WIDTH;

        Cell& cell = grid[row][col];

        if (cell.getMinesAround() == -1)
            continue;

        cell.setMinesAround(-1);
        i++;
    }

    for (int row = 0; row < GRID_HEIGHT; ++row)
    {
        for (int col = 0; col < GRID_WIDTH; ++col)
        {
            Cell& cell = grid[row][col];

            if (cell.getMinesAround() == -1)
                continue;

            int mineCount = 0;

            for (int dy = -1; dy <= 1; ++dy)
            {
                for (int dx = -1; dx <= 1; ++dx)
                {
                    int newRow = row + dy;
                    int newCol = col + dx;

                    if (newRow < 0 || newRow >= GRID_HEIGHT || newCol < 0 || newCol >= GRID_WIDTH)
                        continue;

                    if (grid[newRow][newCol].getMinesAround() == -1)
                        mineCount++;
                }
            }

            cell.setMinesAround(mineCount);
        }
    }

    for (int row = 0; row < GRID_HEIGHT; ++row)
    {
        for (int col = 0; col < GRID_WIDTH; ++col)
        {
            Cell& cell = grid[row][col];
            
            switch(cell.getMinesAround())
            {
                case 1: { grid[row][col].setActual(mine1); break; }
                case 2: { grid[row][col].setActual(mine2); break; }
                case 3: { grid[row][col].setActual(mine3); break; }
                case 4: { grid[row][col].setActual(mine4); break; }
                case 5: { grid[row][col].setActual(mine5); break; }
                case 6: { grid[row][col].setActual(mine6); break; }
                case 7: { grid[row][col].setActual(mine7); break; }
                case 8: { grid[row][col].setActual(mine8); break; }
                case 9: { grid[row][col].setActual(mine9); break; }
                case 0: { grid[row][col].setActual(openbox); break; }
                case -1: { grid[row][col].setActual(mine); break; }
            }
        }
    }
}