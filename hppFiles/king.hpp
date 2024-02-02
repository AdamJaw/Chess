#ifndef KING
#define KING
#include "chessman.hpp"
#include "binaryboard.hpp"

class King: public Chessman{

public:
King(int);
void makeListOfPossibleMoves(BinaryBoard,int,int);
void makeListOfPossibleCaptures(BinaryBoard,int,int);
};

#endif