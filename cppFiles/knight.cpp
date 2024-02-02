#include "knight.hpp"

Knight::Knight(int figureColor)
{
    c_classType=2;
    c_figureColor=figureColor;
}

void Knight::makeListOfPossibleMoves(BinaryBoard binaryBoard,int X,int Y){
    c_possibleMoves.clear();
    if((binaryBoard.c_binaryBoard[X-1][Y+2]==BLANK_FIELD)&&((X-1)<MAP_WIDTH)&&((Y+2)<MAP_WIDTH)&&((X-1)>=0)&&((Y+2)>=0)){
        c_possibleMoves.push_back(boardCoordinatesToIndex(Y+2,X-1));
    }
    if((binaryBoard.c_binaryBoard[X+1][Y+2]==BLANK_FIELD)&&((X+1)<MAP_WIDTH)&&((Y+2)<MAP_WIDTH)&&((X+1)>=0)&&((Y+2)>=0)){
        c_possibleMoves.push_back(boardCoordinatesToIndex(Y+2,X+1));
    }
    if((binaryBoard.c_binaryBoard[X+2][Y+1]==BLANK_FIELD)&&((X+2)<MAP_WIDTH)&&((Y+1)<MAP_WIDTH)&&((X+2)>=0)&&((Y+1)>=0)){
        c_possibleMoves.push_back(boardCoordinatesToIndex(Y+1,X+2));
    }
    if((binaryBoard.c_binaryBoard[X+2][Y-1]==BLANK_FIELD)&&((X+2)<MAP_WIDTH)&&((Y-1)<MAP_WIDTH)&&((X+2)>=0)&&((Y-1)>=0)){
        c_possibleMoves.push_back(boardCoordinatesToIndex(Y-1,X+2));
    }
    if((binaryBoard.c_binaryBoard[X+1][Y-2]==BLANK_FIELD)&&((X+1)<MAP_WIDTH)&&((Y-2)<MAP_WIDTH)&&((X+1)>=0)&&((Y-2)>=0)){
        c_possibleMoves.push_back(boardCoordinatesToIndex(Y-2,X+1));
    }
    if((binaryBoard.c_binaryBoard[X-1][Y-2]==BLANK_FIELD)&&((X-1)<MAP_WIDTH)&&((Y-2)<MAP_WIDTH)&&((X-1)>=0)&&((Y-2)>=0)){
        c_possibleMoves.push_back(boardCoordinatesToIndex(Y-2,X-1));
    }
    if((binaryBoard.c_binaryBoard[X-2][Y-1]==BLANK_FIELD)&&((X-2)<MAP_WIDTH)&&((Y-1)<MAP_WIDTH)&&((X-2)>=0)&&((Y-1)>=0)){
        c_possibleMoves.push_back(boardCoordinatesToIndex(Y-1,X-2));
    }
    if((binaryBoard.c_binaryBoard[X-2][Y+1]==BLANK_FIELD)&&((X-2)<MAP_WIDTH)&&((Y+1)<MAP_WIDTH)&&((X-2)>=0)&&((Y+1)>=0)){
        c_possibleMoves.push_back(boardCoordinatesToIndex(Y+1,X-2));
    }    
}

void Knight::makeListOfPossibleCaptures(BinaryBoard binaryBoard,int X,int Y){
    c_possibleCaptures.clear();

    if((binaryBoard.c_binaryBoard[X-1][Y+2]!=BLANK_FIELD)&&(binaryBoard.c_binaryBoard[X-1][Y+2]!=c_figureColor)&&((X-1)<MAP_WIDTH)&&((Y+2)<MAP_WIDTH)&&((X-1)>=0)&&((Y+2)>=0)){
        c_possibleCaptures.push_back(boardCoordinatesToIndex(Y+2,X-1));
    }
    if((binaryBoard.c_binaryBoard[X+1][Y+2]!=BLANK_FIELD)&&(binaryBoard.c_binaryBoard[X+1][Y+2]!=c_figureColor)&&((X+1)<MAP_WIDTH)&&((Y+2)<MAP_WIDTH)&&((X+1)>=0)&&((Y+2)>=0)){
        c_possibleCaptures.push_back(boardCoordinatesToIndex(Y+2,X+1));
    }
    if((binaryBoard.c_binaryBoard[X+2][Y+1]!=BLANK_FIELD)&&(binaryBoard.c_binaryBoard[X+2][Y+1]!=c_figureColor)&&((X+2)<MAP_WIDTH)&&((Y+1)<MAP_WIDTH)&&((X+2)>=0)&&((Y+1)>=0)){
        c_possibleCaptures.push_back(boardCoordinatesToIndex(Y+1,X+2));
    }
    if((binaryBoard.c_binaryBoard[X+2][Y-1]!=BLANK_FIELD)&&(binaryBoard.c_binaryBoard[X+2][Y-1]!=c_figureColor)&&((X+2)<MAP_WIDTH)&&((Y-1)<MAP_WIDTH)&&((X+2)>=0)&&((Y-1)>=0)){
        c_possibleCaptures.push_back(boardCoordinatesToIndex(Y-1,X+2));
    }
    if((binaryBoard.c_binaryBoard[X+1][Y-2]!=BLANK_FIELD)&&(binaryBoard.c_binaryBoard[X+1][Y-2]!=c_figureColor)&&((X+1)<MAP_WIDTH)&&((Y-2)<MAP_WIDTH)&&((X+1)>=0)&&((Y-2)>=0)){
        c_possibleCaptures.push_back(boardCoordinatesToIndex(Y-2,X+1));
    }
    if((binaryBoard.c_binaryBoard[X-1][Y-2]!=BLANK_FIELD)&&(binaryBoard.c_binaryBoard[X-1][Y-2]!=c_figureColor)&&((X-1)<MAP_WIDTH)&&((Y-2)<MAP_WIDTH)&&((X-1)>=0)&&((Y-2)>=0)){
        c_possibleCaptures.push_back(boardCoordinatesToIndex(Y-2,X-1));
    }
    if((binaryBoard.c_binaryBoard[X-2][Y-1]!=BLANK_FIELD)&&(binaryBoard.c_binaryBoard[X-2][Y-1]!=c_figureColor)&&((X-2)<MAP_WIDTH)&&((Y-1)<MAP_WIDTH)&&((X-2)>=0)&&((Y-1)>=0)){
        c_possibleCaptures.push_back(boardCoordinatesToIndex(Y-1,X-2));
    }
    if((binaryBoard.c_binaryBoard[X-2][Y+1]!=BLANK_FIELD)&&(binaryBoard.c_binaryBoard[X-2][Y+1]!=c_figureColor)&&((X-2)<MAP_WIDTH)&&((Y+1)<MAP_WIDTH)&&((X-2)>=0)&&((Y+1)>=0)){
        c_possibleCaptures.push_back(boardCoordinatesToIndex(Y+1,X-2));
    }
}