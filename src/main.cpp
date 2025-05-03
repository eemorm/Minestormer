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

    // sf::Texture texture;
    // if (!texture.loadFromFile("resources/minestormertiles.png"))
    //{
    //	std::cerr << "Error loading spritesheet!" << std::endl;
    //	return -1;
    // }

    // sf::Sprite spritesheet(texture);

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

        window.clear();
        // window.draw(spritesheet);
        window.clear(sf::Color(127, 127, 127));
        window.display();
    }

    return 0;
}