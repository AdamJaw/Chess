#ifndef ROOK
#define ROOK
#include "chessman.hpp"
#include "binaryboard.hpp"
#include "converter.hpp"

class Rook: public Chessman{

public:
Rook(int);
void makeListOfPossibleMoves(BinaryBoard,int,int);
void makeListOfPossibleCaptures(BinaryBoard,int,int);
};

#endif