#include "bishop.hpp"

Bishop::Bishop(int figureColor)
{
    c_classType=1;
    c_figureColor=figureColor;
}

void Bishop::makeListOfPossibleMoves(BinaryBoard binaryBoard,int X,int Y){
    c_possibleMoves.clear();

    int i=1;
    while((binaryBoard.c_binaryBoard[X+i][Y+i]==BLANK_FIELD)&&((X+i)<MAP_WIDTH)&&((Y+i)<MAP_WIDTH)&&((X+i)>=0)&&((Y+i)>=0)){
        c_possibleMoves.push_back(boardCoordinatesToIndex(Y+i,X+i));
        i++;
    }
    i=1;
    while((binaryBoard.c_binaryBoard[X-i][Y+i]==BLANK_FIELD)&&((X-i)<MAP_WIDTH)&&((Y+i)<MAP_WIDTH)&&((X-i)>=0)&&((Y+i)>=0)){
        c_possibleMoves.push_back(boardCoordinatesToIndex(Y+i,X-i));
        i++;
    }
    i=1;
    while((binaryBoard.c_binaryBoard[X+i][Y-i]==BLANK_FIELD)&&((X+i)<MAP_WIDTH)&&((Y-i)<MAP_WIDTH)&&((X+i)>=0)&&((Y-i)>=0)){
        c_possibleMoves.push_back(boardCoordinatesToIndex(Y-i,X+i));
        i++;
    }
    i=1;
    while((binaryBoard.c_binaryBoard[X-i][Y-i]==BLANK_FIELD)&&((X-i)<MAP_WIDTH)&&((Y-i)<MAP_WIDTH)&&((X-i)>=0)&&((Y-i)>=0)){
        c_possibleMoves.push_back(boardCoordinatesToIndex(Y-i,X-i));
        i++;
    }
}

void Bishop::makeListOfPossibleCaptures(BinaryBoard binaryBoard,int X,int Y){
    c_possibleCaptures.clear();

    int i=1;
    while((binaryBoard.c_binaryBoard[X+i][Y+i]==BLANK_FIELD)&&((X+i)<MAP_WIDTH)&&((Y+i)<MAP_WIDTH)&&((X+i)>=0)&&((Y+i)>=0)){
        i++;
    }
    if(((X+i)<MAP_WIDTH)&&((Y+i)<MAP_WIDTH)&&((X+i)>=0)&&((Y+i)>=0)){
        if((binaryBoard.c_binaryBoard[X+i][Y+i]!=BLANK_FIELD)&&(binaryBoard.c_binaryBoard[X+i][Y+i]!=c_figureColor)){
            c_possibleCaptures.push_back(boardCoordinatesToIndex(Y+i,X+i));
        }
    }
    i=1;
    while((binaryBoard.c_binaryBoard[X-i][Y+i]==BLANK_FIELD)&&((X-i)<MAP_WIDTH)&&((Y+i)<MAP_WIDTH)&&((X-i)>=0)&&((Y+i)>=0)){
        i++;
    }
    if(((X-i)<MAP_WIDTH)&&((Y+i)<MAP_WIDTH)&&((X-i)>=0)&&((Y+i)>=0)){
        if((binaryBoard.c_binaryBoard[X-i][Y+i]!=BLANK_FIELD)&&(binaryBoard.c_binaryBoard[X-i][Y+i]!=c_figureColor)){
            c_possibleCaptures.push_back(boardCoordinatesToIndex(Y+i,X-i));
        }
    }
    i=1;
    while((binaryBoard.c_binaryBoard[X+i][Y-i]==BLANK_FIELD)&&((X+i)<MAP_WIDTH)&&((Y-i)<MAP_WIDTH)&&((X+i)>=0)&&((Y-i)>=0)){
        i++;
    }
    if(((X+i)<MAP_WIDTH)&&((Y-i)<MAP_WIDTH)&&((X+i)>=0)&&((Y-i)>=0)){
        if((binaryBoard.c_binaryBoard[X+i][Y-i]!=BLANK_FIELD)&&(binaryBoard.c_binaryBoard[X+i][Y-i]!=c_figureColor)){
            c_possibleCaptures.push_back(boardCoordinatesToIndex(Y-i,X+i));
        }
    }
    i=1;
    while((binaryBoard.c_binaryBoard[X-i][Y-i]==BLANK_FIELD)&&((X-i)<MAP_WIDTH)&&((Y-i)<MAP_WIDTH)&&((X-i)>=0)&&((Y-i)>=0)){
        i++;
    }
    if(((X-i)<MAP_WIDTH)&&((Y-i)<MAP_WIDTH)&&((X-i)>=0)&&((Y-i)>=0)){
        if((binaryBoard.c_binaryBoard[X-i][Y-i]!=BLANK_FIELD)&&(binaryBoard.c_binaryBoard[X-i][Y-i]!=c_figureColor)){
            c_possibleCaptures.push_back(boardCoordinatesToIndex(Y-i,X-i));
        }
    }
}