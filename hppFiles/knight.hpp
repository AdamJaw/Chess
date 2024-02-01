#ifndef KNIGHT
#define KNIGHT
#include "chessman.hpp"
#include "binaryboard.hpp"

class Knight: public Chessman{

public:
Knight(int);
void makeListOfPossibleMoves(BinaryBoard,int,int);
void makeListOfPossibleCaptures(BinaryBoard,int,int);
};

#endif