#ifndef CHESSMAN
#define CHESSMAN
#include <vector>
#include <string>
#include <array>
#include "converter.hpp"

class Chessman{
public:
int c_positionX;
int c_positionY;
std::vector<int> c_possibleMoves;
std::vector<int> c_possibleCaptures;
std::string c_classType;
int c_figureColor;

public:
int moveFigure(int,int,std::array<std::array<Chessman*,MAP_WIDTH>,MAP_WIDTH>&);
virtual void makeListOfPossibleMoves(std::array<std::array<Chessman*,MAP_WIDTH>,MAP_WIDTH>&)=0;

};

#endif