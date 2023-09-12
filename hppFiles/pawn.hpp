#ifndef PAWN
#define PAWN
#include "chessman.hpp"
#include "converter.hpp"
#include <array>

class Pawn: public Chessman{
public:
bool c_firstMove;

public:
Pawn(int,int,int);
void makeListOfPossibleMoves(std::array<std::array<Chessman*,MAP_WIDTH>,MAP_WIDTH>&);

};

#endif