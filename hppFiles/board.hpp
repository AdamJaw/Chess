#ifndef PAWN
#define PAWN
#include <array>
#include "chessman.hpp"

const int MAP_WIDTH=8;

class Board{
private:
std::array<std::array<Chessman*,8>,8> c_board;

};

#endif