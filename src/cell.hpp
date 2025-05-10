#pragma once
// Textures
#include "textures.hpp"
#include "sizing.hpp"
#include "grid.hpp"

// SFML
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

// Basic
#include <iostream>

class Cell
{
  private:
    sf::Sprite hidden = closedbox;
    sf::Sprite flag = marktile;
    sf::Sprite actual;
    sf::Sprite sprite = hidden;
    int minesAround;
    bool revealed = false;
    bool flagged = false;
    int row = -1, col = -1;

  public:
    Cell() {}
    ~Cell() {}

    void setCoords(int r, int c)
    {
        row = r;
        col = c;
    }
    int getRow() const { return row; }
    int getCol() const { return col; }

    sf::Sprite getHidden() { return hidden; }
    void setActual(sf::Sprite a) { actual = a; }
    sf::Sprite getActual() { return actual; }
    void setSprite(sf::Sprite s) { sprite = s; }
    sf::Sprite getSprite() { return sprite; }
    void setMinesAround(int m) { minesAround = m; }
    int getMinesAround() { return minesAround; }
    bool getRevealed() { return revealed; }
    bool getFlagged() { return flagged; }

    void revealTile();
    void flagTile()
    {
        flagged = true;
        sprite = flag;
    }
    void unflagTile()
    {
        flagged = false;
        sprite = hidden;
    }
};