#include "king.hpp"

King::King(int figureColor)
{
    c_classType=5;
    c_figureColor=figureColor;
    isKing=1;
}

void King::makeListOfPossibleMoves(BinaryBoard binaryBoard,int X,int Y){
    c_possibleMoves.clear();
    if((binaryBoard.c_binaryBoard[X-1][Y]==BLANK_FIELD)&&((X-1)<MAP_WIDTH)&&(Y<MAP_WIDTH)&&((X-1)>=0)&&(Y>=0)){
        c_possibleMoves.push_back(boardCoordinatesToIndex(Y,X-1));
    }
    if((binaryBoard.c_binaryBoard[X-1][Y+1]==BLANK_FIELD)&&((X-1)<MAP_WIDTH)&&((Y+1)<MAP_WIDTH)&&((X-1)>=0)&&((Y+1)>=0)){
        c_possibleMoves.push_back(boardCoordinatesToIndex(Y+1,X-1));
    }
    if((binaryBoard.c_binaryBoard[X][Y+1]==BLANK_FIELD)&&((X)<MAP_WIDTH)&&((Y+1)<MAP_WIDTH)&&((X)>=0)&&((Y+1)>=0)){
        c_possibleMoves.push_back(boardCoordinatesToIndex(Y+1,X));
    }
    if((binaryBoard.c_binaryBoard[X+1][Y+1]==BLANK_FIELD)&&((X+1)<MAP_WIDTH)&&((Y+1)<MAP_WIDTH)&&((X+1)>=0)&&((Y+1)>=0)){
        c_possibleMoves.push_back(boardCoordinatesToIndex(Y+1,X+1));
    }
    if((binaryBoard.c_binaryBoard[X+1][Y]==BLANK_FIELD)&&((X+1)<MAP_WIDTH)&&((Y)<MAP_WIDTH)&&((X+1)>=0)&&((Y)>=0)){
        c_possibleMoves.push_back(boardCoordinatesToIndex(Y,X+1));
    }
    if((binaryBoard.c_binaryBoard[X+1][Y-1]==BLANK_FIELD)&&((X+1)<MAP_WIDTH)&&((Y-1)<MAP_WIDTH)&&((X+1)>=0)&&((Y-1)>=0)){
        c_possibleMoves.push_back(boardCoordinatesToIndex(Y-1,X+1));
    }
    if((binaryBoard.c_binaryBoard[X][Y-1]==BLANK_FIELD)&&(X<MAP_WIDTH)&&((Y-1)<MAP_WIDTH)&&(X>=0)&&((Y-1)>=0)){
        c_possibleMoves.push_back(boardCoordinatesToIndex(Y-1,X));
    }
    if((binaryBoard.c_binaryBoard[X-1][Y-1]==BLANK_FIELD)&&((X-1)<MAP_WIDTH)&&((Y-1)<MAP_WIDTH)&&((X-1)>=0)&&((Y-1)>=0)){
        c_possibleMoves.push_back(boardCoordinatesToIndex(Y-1,X-1));
    }
}

void King::makeListOfPossibleCaptures(BinaryBoard binaryBoard,int X,int Y){
    c_possibleCaptures.clear();
    if((binaryBoard.c_binaryBoard[X-1][Y]!=BLANK_FIELD)&&(binaryBoard.c_binaryBoard[X-1][Y]!=c_figureColor)&&((X-1)<MAP_WIDTH)&&(Y<MAP_WIDTH)&&((X-1)>=0)&&(Y>=0)){
        c_possibleMoves.push_back(boardCoordinatesToIndex(Y,X-1));
    }
    if((binaryBoard.c_binaryBoard[X-1][Y+1]!=BLANK_FIELD)&&(binaryBoard.c_binaryBoard[X-1][Y+1]!=c_figureColor)&&((X-1)<MAP_WIDTH)&&((Y+1)<MAP_WIDTH)&&((X-1)>=0)&&((Y+1)>=0)){
        c_possibleMoves.push_back(boardCoordinatesToIndex(Y+1,X-1));
    }
    if((binaryBoard.c_binaryBoard[X][Y+1]!=BLANK_FIELD)&&(binaryBoard.c_binaryBoard[X][Y+1]!=c_figureColor)&&((X)<MAP_WIDTH)&&((Y+1)<MAP_WIDTH)&&((X)>=0)&&((Y+1)>=0)){
        c_possibleMoves.push_back(boardCoordinatesToIndex(Y+1,X));
    }
    if((binaryBoard.c_binaryBoard[X+1][Y+1]!=BLANK_FIELD)&&(binaryBoard.c_binaryBoard[X+1][Y+1]!=c_figureColor)&&((X+1)<MAP_WIDTH)&&((Y+1)<MAP_WIDTH)&&((X+1)>=0)&&((Y+1)>=0)){
        c_possibleMoves.push_back(boardCoordinatesToIndex(Y+1,X+1));
    }
    if((binaryBoard.c_binaryBoard[X+1][Y]!=BLANK_FIELD)&&(binaryBoard.c_binaryBoard[X+1][Y]!=c_figureColor)&&((X+1)<MAP_WIDTH)&&((Y)<MAP_WIDTH)&&((X+1)>=0)&&((Y)>=0)){
        c_possibleMoves.push_back(boardCoordinatesToIndex(Y,X+1));
    }
    if((binaryBoard.c_binaryBoard[X+1][Y-1]!=BLANK_FIELD)&&(binaryBoard.c_binaryBoard[X+1][Y-1]!=c_figureColor)&&((X+1)<MAP_WIDTH)&&((Y-1)<MAP_WIDTH)&&((X+1)>=0)&&((Y-1)>=0)){
        c_possibleMoves.push_back(boardCoordinatesToIndex(Y-1,X+1));
    }
    if((binaryBoard.c_binaryBoard[X][Y-1]!=BLANK_FIELD)&&(binaryBoard.c_binaryBoard[X][Y-1]!=c_figureColor)&&(X<MAP_WIDTH)&&((Y-1)<MAP_WIDTH)&&(X>=0)&&((Y-1)>=0)){
        c_possibleMoves.push_back(boardCoordinatesToIndex(Y-1,X));
    }
    if((binaryBoard.c_binaryBoard[X-1][Y-1]!=BLANK_FIELD)&&(binaryBoard.c_binaryBoard[X-1][Y-1]!=c_figureColor)&&((X-1)<MAP_WIDTH)&&((Y-1)<MAP_WIDTH)&&((X-1)>=0)&&((Y-1)>=0)){
        c_possibleMoves.push_back(boardCoordinatesToIndex(Y-1,X-1));
    }
}