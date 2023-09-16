#include "converter.hpp"
#include "board.hpp"

int boardCoordinatesToIndex(int Y, int X){
    return ((Y*MAP_WIDTH+X));
}