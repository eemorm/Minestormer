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
        sf::Sprite texture;
        int minesAround;
    public:
        void reveal()
        {
            
        }
};
