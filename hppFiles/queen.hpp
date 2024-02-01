#ifndef QUEEN
#define QUEEN
#include "chessman.hpp"
#include "binaryboard.hpp"

class Queen: public Chessman{

public:
Queen(int);
void makeListOfPossibleMoves(BinaryBoard,int,int);
void makeListOfPossibleCaptures(BinaryBoard,int,int);
};

#endif