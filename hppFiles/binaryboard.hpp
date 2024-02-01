#ifndef BINARYBOARD
#define BINARYBOARD
#include "converter.hpp"

const int BLANK_FIELD=2;

class BinaryBoard{
public:
int c_binaryBoard[MAP_WIDTH][MAP_WIDTH];

public:
BinaryBoard();
void moveBinaryPiece(int,int,int,int);

};

#endif