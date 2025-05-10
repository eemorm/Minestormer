// Textures
#include "grid.hpp"
#include "sizing.hpp"
#include "textures.hpp"
#include "death.hpp"

// SFML
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

// Basic
#include <iostream>

void Cell::revealTile()
{
    if (revealed)
        return;

    revealed = true;
    sprite = actual;

    if (minesAround == 0)
    {
        revealEmptyCells(row, col);
    }
    else if (minesAround == -1)
    {

    }
}
