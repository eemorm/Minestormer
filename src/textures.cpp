#include "textures.hpp"
#include "sizing.hpp"
#include <iostream>

// Define the global texture and sprites
sf::Texture texture;

sf::Sprite mine1;
sf::Sprite mine2;
sf::Sprite mine3;
sf::Sprite mine4;
sf::Sprite mine5;
sf::Sprite mine6;
sf::Sprite mine7;
sf::Sprite mine8;
sf::Sprite mine9;
sf::Sprite marktile;
sf::Sprite closedbox;
sf::Sprite openbox;
sf::Sprite bottomleft;
sf::Sprite lefttop;
sf::Sprite topright;
sf::Sprite rightbottom;
sf::Sprite bottom;
sf::Sprite left;
sf::Sprite top;
sf::Sprite right;
sf::Sprite rightbottomleft;
sf::Sprite bottomlefttop;
sf::Sprite lefttopright;
sf::Sprite toprightbottom;
sf::Sprite leftright;
sf::Sprite topbottom;
sf::Sprite mine;

// Load textures into the sprites
bool loadTextures()
{
    if (!texture.loadFromFile("assets/minestormertiles.png"))
    {
        std::cerr << "Error loading spritesheet!" << std::endl;
        return false;
    }

    mine1.setTexture(texture);
    mine1.setTextureRect(sf::IntRect(0 * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE));
    mine2.setTexture(texture);
    mine2.setTextureRect(sf::IntRect(1 * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE));
    mine3.setTexture(texture);
    mine3.setTextureRect(sf::IntRect(2 * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE));
    mine4.setTexture(texture);
    mine4.setTextureRect(sf::IntRect(3 * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE));
    mine5.setTexture(texture);
    mine5.setTextureRect(sf::IntRect(4 * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE));
    mine6.setTexture(texture);
    mine6.setTextureRect(sf::IntRect(5 * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE));
    mine7.setTexture(texture);
    mine7.setTextureRect(sf::IntRect(6 * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE));
    mine8.setTexture(texture);
    mine8.setTextureRect(sf::IntRect(7 * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE));
    mine9.setTexture(texture);
    mine9.setTextureRect(sf::IntRect(8 * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE));
    marktile.setTexture(texture);
    marktile.setTextureRect(sf::IntRect(9 * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE));
    closedbox.setTexture(texture);
    closedbox.setTextureRect(sf::IntRect(10 * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE));
    openbox.setTexture(texture);
    openbox.setTextureRect(sf::IntRect(11 * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE));
    bottomleft.setTexture(texture);
    bottomleft.setTextureRect(sf::IntRect(12 * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE));
    lefttop.setTexture(texture);
    lefttop.setTextureRect(sf::IntRect(13 * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE));
    topright.setTexture(texture);
    topright.setTextureRect(sf::IntRect(14 * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE));
    rightbottom.setTexture(texture);
    rightbottom.setTextureRect(sf::IntRect(15 * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE));
    bottom.setTexture(texture);
    bottom.setTextureRect(sf::IntRect(16 * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE));
    left.setTexture(texture);
    left.setTextureRect(sf::IntRect(17 * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE));
    top.setTexture(texture);
    top.setTextureRect(sf::IntRect(18 * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE));
    right.setTexture(texture);
    right.setTextureRect(sf::IntRect(19 * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE));
    rightbottomleft.setTexture(texture);
    rightbottomleft.setTextureRect(sf::IntRect(20 * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE));
    bottomlefttop.setTexture(texture);
    bottomlefttop.setTextureRect(sf::IntRect(21 * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE));
    lefttopright.setTexture(texture);
    lefttopright.setTextureRect(sf::IntRect(22 * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE));
    toprightbottom.setTexture(texture);
    toprightbottom.setTextureRect(sf::IntRect(23 * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE));
    leftright.setTexture(texture);
    leftright.setTextureRect(sf::IntRect(24 * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE));
    topbottom.setTexture(texture);
    topbottom.setTextureRect(sf::IntRect(25 * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE));
    mine.setTexture(texture);
    mine.setTextureRect(sf::IntRect(28 * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE));

    return true;
}