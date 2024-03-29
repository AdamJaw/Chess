#ifndef PAWN
#define PAWN
#include "chessman.hpp"
#include "binaryboard.hpp"
#include "converter.hpp"

class Pawn: public Chessman{
public:
int c_startingSide;
bool c_firstMove;

public:
Pawn(int,int);
void makeListOfPossibleMoves(BinaryBoard,int,int);
void makeListOfPossibleCaptures(BinaryBoard,int,int);

};

#endif