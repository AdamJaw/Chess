#ifndef KING
#define KING
#include "chessman.hpp"
#include "binaryboard.hpp"

class King: public Chessman{

public:
King(int);
void makeListOfPossibleMoves(BinaryBoard);
};

#endif