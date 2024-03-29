#include "pawn.hpp"

Pawn::Pawn(int figureColor, int startingSide)
{
    c_classType=0;
    c_figureColor=figureColor;
    c_startingSide=startingSide;// zero (0) is from bottom and one (1) is from top of board
    c_firstMove=true;
    isKing=0;
}

void Pawn::makeListOfPossibleMoves(BinaryBoard binaryBoard, int X, int Y){
    c_possibleMoves.clear();

    if(!c_firstMove){
        if(c_startingSide==0){
            if(binaryBoard.c_binaryBoard[X][Y-1]==BLANK_FIELD){
                c_possibleMoves.push_back(boardCoordinatesToIndex(Y-1,X));
            }
        }
        if(c_startingSide==1){
            if(binaryBoard.c_binaryBoard[X][Y+1]==BLANK_FIELD){
                c_possibleMoves.push_back(boardCoordinatesToIndex(Y+1,X));
            }
        }
    }

    if(c_firstMove){
        c_firstMove=false;
        if(c_startingSide==0){
            if((binaryBoard.c_binaryBoard[X][Y-1]==BLANK_FIELD)&&((X)<MAP_WIDTH)&&((Y-1)<MAP_WIDTH)&&((X)>=0)&&((Y-1)>=0)){
                c_possibleMoves.push_back(boardCoordinatesToIndex(Y-1,X));
            }
            if((binaryBoard.c_binaryBoard[X][Y-1]==BLANK_FIELD)&&(binaryBoard.c_binaryBoard[X][Y-2]==BLANK_FIELD)&&((X)<MAP_WIDTH)&&((Y-2)<MAP_WIDTH)&&((X)>=0)&&((Y-2)>=0)){
                c_possibleMoves.push_back(boardCoordinatesToIndex(Y-2,X));
            }
        }
        if(c_startingSide==1){
            if(binaryBoard.c_binaryBoard[X][Y+1]==BLANK_FIELD){
                c_possibleMoves.push_back(boardCoordinatesToIndex(Y+1,X)&&((X)<MAP_WIDTH)&&((Y+1)<MAP_WIDTH)&&((X)>=0)&&((Y+1)>=0));
            }
            if((binaryBoard.c_binaryBoard[X][Y+1]==BLANK_FIELD)&&(binaryBoard.c_binaryBoard[X][Y+2]==BLANK_FIELD)&&((X)<MAP_WIDTH)&&((Y+2)<MAP_WIDTH)&&((X)>=0)&&((Y+2)>=0)){
                c_possibleMoves.push_back(boardCoordinatesToIndex(Y+2,X));
            }
        }
    }
}

void Pawn::makeListOfPossibleCaptures(BinaryBoard binaryBoard, int X, int Y){
    c_possibleCaptures.clear();
    
    if(c_startingSide==0){
        if((binaryBoard.c_binaryBoard[X+1][Y-1]!=BLANK_FIELD)&&(binaryBoard.c_binaryBoard[X+1][Y-1]!=c_figureColor)&&((X+1)<MAP_WIDTH)&&((Y-1)<MAP_WIDTH)&&((X+1)>=0)&&((Y-1)>=0)){
            c_possibleCaptures.push_back(boardCoordinatesToIndex(Y-1,X+1));
        }
        if((binaryBoard.c_binaryBoard[X-1][Y-1]!=BLANK_FIELD)&&(binaryBoard.c_binaryBoard[X-1][Y-1]!=c_figureColor)&&((X-1)<MAP_WIDTH)&&((Y-1)<MAP_WIDTH)&&((X-1)>=0)&&((Y-1)>=0)){
            c_possibleCaptures.push_back(boardCoordinatesToIndex(Y-1,X-1));
        }
    }
    if(c_startingSide==1){
        if((binaryBoard.c_binaryBoard[X+1][Y+1]!=BLANK_FIELD)&&(binaryBoard.c_binaryBoard[X+1][Y+1]!=c_figureColor)&&((X+1)<MAP_WIDTH)&&((Y+1)<MAP_WIDTH)&&((X+1)>=0)&&((Y+1)>=0)){
            c_possibleCaptures.push_back(boardCoordinatesToIndex(Y+1,X+1));
        }
        if((binaryBoard.c_binaryBoard[X-1][Y+1]!=BLANK_FIELD)&&(binaryBoard.c_binaryBoard[X-1][Y+1]!=c_figureColor)&&((X-1)<MAP_WIDTH)&&((Y+1)<MAP_WIDTH)&&((X-1)>=0)&&((Y+1)>=0)){
            c_possibleCaptures.push_back(boardCoordinatesToIndex(Y+1,X-1));
        }
    }
}
