#ifndef PAWN
#define PAWN
#include "chessman.hpp"

class Pawn: public Chessman{

public:
void makeListOfPossibleMoves(std::vector<std::vector<Chessman*>>);

};

#endif