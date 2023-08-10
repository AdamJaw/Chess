#ifndef CHESSMAN
#define CHESSMAN
#include <vector>

class Chessman{
public:
int c_positionX;
int c_positionY;
std::vector<int> c_possibleMoves;

public:
void moveFigure(int,int);
virtual void makeListOfPossibleMoves(std::vector<std::vector<Chessman*>>)=0;

};

#endif