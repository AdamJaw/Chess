#include "converter.hpp"

int boardCoordinatesToIndex(int Y, int X){
    return ((Y*MAP_WIDTH+X));
}

Point indexToBoardCoordinates(int index){
    Point point;
    point.X=index%MAP_WIDTH;
    point.Y=index/MAP_WIDTH;
    return point;
}