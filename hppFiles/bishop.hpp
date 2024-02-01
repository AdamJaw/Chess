#ifndef BISHOP
#define BISHOP
#include "chessman.hpp"
#include "binaryboard.hpp"

class Bishop: public Chessman{

public:
Bishop(int);
void makeListOfPossibleMoves(BinaryBoard,int,int);
void makeListOfPossibleCaptures(BinaryBoard,int,int);
};

#endif