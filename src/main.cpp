// Textures
#include "textures.hpp"

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
    sf::RenderWindow window(sf::VideoMode({640, 480}), "Minestormer", sf::Style::Close);

    if (!loadTextures())
    {
        return -1;
    }

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
        window.draw(mine1);
        window.display();
    }

    return 0;
}