#ifndef CONVERTER
#define CONVERTER

const int MAP_WIDTH=8;
const int TILE_WIDTH=100;

struct Point{
    int X;
    int Y;
};

int boardCoordinatesToIndex(int,int);
Point indexToBoardCoordinates(int);

#endif