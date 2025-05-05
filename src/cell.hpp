#pragma once
// Textures
#include "textures.hpp"

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
        sf::Sprite sprite;
        int minesAround;
    public:
        Cell() {}
        ~Cell() {}
        sf::Sprite getHidden() { return hidden; }
        void setSprite(sf::Sprite s) { sprite = s; }
        sf::Sprite getSprite() { return sprite; }
        void setMinesAround(int m) { minesAround = m; }
        int getMinesAround() { return minesAround; }
        void reveal()
        {
            
        }
};