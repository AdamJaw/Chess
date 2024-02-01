#ifndef CHESSMAN
#define CHESSMAN
#include <vector>
#include <array>
#include "binaryboard.hpp"

class Chessman{
public:
int c_positionX;
int c_positionY;
std::vector<int> c_possibleMoves;
std::vector<int> c_possibleCaptures;
int c_classType;
int c_figureColor;

public:
virtual void makeListOfPossibleMoves(BinaryBoard,int,int){
    c_possibleMoves.clear();
};
virtual void makeListOfPossibleCaptures(BinaryBoard,int,int){
    c_possibleCaptures.clear();
};

};

#endif