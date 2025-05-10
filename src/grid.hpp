#pragma once
//Custom Includes
#include "textures.hpp"
#include "cell.hpp"

//Basic
#include <iostream>
#include <vector>

// SFML
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Cell;

extern std::vector<std::vector<Cell>> grid;

void initializeGrid();
void drawGrid(sf::RenderWindow& window);
void revealEmptyCells(int row, int col);