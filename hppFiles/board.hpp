#ifndef BOARD
#define BOARD
#include <array>
#include "chessman.hpp"
#include <SFML/Graphics.hpp>
#include "converter.hpp"
#include "rook.hpp"
#include "pawn.hpp"
#include "bishop.hpp"
#include "king.hpp"
#include "knight.hpp"
#include "queen.hpp"
#include "structures.hpp"

class Board{
public:
std::array<std::array<Chessman*,MAP_WIDTH>,MAP_WIDTH> c_board;
sf::RectangleShape c_blankFields[MAP_WIDTH][MAP_WIDTH];
sf::RectangleShape c_figureFields[MAP_WIDTH][MAP_WIDTH];
sf::Texture c_texture;
Position c_mousePos;
Position c_actualPiece;
Position c_atualPosition;
Position c_actualEnemyPiece;
int c_howManyPossibleMoves;
int c_howManyPossibleCaptures;
int c_playerTurn;
bool c_isPieceSelected;

public:
Board();
void makeBoardWithoutFigures();
void assignDefaultPointersForBoard();
void assignDefaultFigureValues();
void setActualPositionOfMouse(sf::Vector2i);
bool setActualPiece();
void setActualBoardPosition();
void movePiece(Position);
};

#endif