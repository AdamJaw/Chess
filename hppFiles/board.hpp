#ifndef BOARD
#define BOARD
#include <array>
#include "chessman.hpp"
#include <SFML/Graphics.hpp>

const int MAP_WIDTH=8;
const int TILE_WIDTH=100;

class Board{
public:
std::array<std::array<Chessman*,MAP_WIDTH>,MAP_WIDTH> c_board;
sf::RectangleShape c_blankFields[MAP_WIDTH][MAP_WIDTH];
sf::RectangleShape c_figureFields[MAP_WIDTH][MAP_WIDTH];
sf::Texture c_texture;

public:
Board();
void makeBoardWithoutFigures();
void assignDefaultFigureValues();
};

#endif