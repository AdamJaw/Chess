#include "rook.hpp"

Rook::Rook(int figureColor)
{
    c_classType=3;
    c_figureColor=figureColor;
    isKing=0;
}

void Rook::makeListOfPossibleMoves(BinaryBoard binaryBoard,int X,int Y){
    c_possibleMoves.clear();

    int i=1;
    while((binaryBoard.c_binaryBoard[X][Y+i]==BLANK_FIELD)&&(X<MAP_WIDTH)&&((Y+i)<MAP_WIDTH)&&(X>=0)&&((Y+i)>=0)){
        c_possibleMoves.push_back(boardCoordinatesToIndex(Y+i,X));
        i++;
    }
    i=1;
    while((binaryBoard.c_binaryBoard[X][Y-i]==BLANK_FIELD)&&(X<MAP_WIDTH)&&((Y-i)<MAP_WIDTH)&&(X>=0)&&((Y-i)>=0)){
        c_possibleMoves.push_back(boardCoordinatesToIndex(Y-i,X));
        i++;
    }
    i=1;
    while((binaryBoard.c_binaryBoard[X+i][Y]==BLANK_FIELD)&&((X+i)<MAP_WIDTH)&&(Y<MAP_WIDTH)&&((X+i)>=0)&&(Y>=0)){
        c_possibleMoves.push_back(boardCoordinatesToIndex(Y,X+i));
        i++;
    }
    i=1;
    while((binaryBoard.c_binaryBoard[X-i][Y]==BLANK_FIELD)&&((X-i)<MAP_WIDTH)&&(Y<MAP_WIDTH)&&((X-i)>=0)&&(Y>=0)){
        c_possibleMoves.push_back(boardCoordinatesToIndex(Y,X-i));
        i++;
    }

}
void Rook::makeListOfPossibleCaptures(BinaryBoard binaryBoard,int X,int Y){
    c_possibleCaptures.clear();

    int i=1;
    while((binaryBoard.c_binaryBoard[X][Y+i]==BLANK_FIELD)&&(X<MAP_WIDTH)&&((Y+i)<MAP_WIDTH)&&(X>=0)&&((Y+i)>=0)){
        i++;
    }
    if((X<MAP_WIDTH)&&((Y+i)<MAP_WIDTH)&&(X>=0)&&((Y+i)>=0)){
        if((binaryBoard.c_binaryBoard[X][Y+i]!=BLANK_FIELD)&&(binaryBoard.c_binaryBoard[X][Y+i]!=c_figureColor)){
            c_possibleCaptures.push_back(boardCoordinatesToIndex(Y+i,X));
        }
    }
    i=1;
    while((binaryBoard.c_binaryBoard[X][Y-i]==BLANK_FIELD)&&(X<MAP_WIDTH)&&((Y-i)<MAP_WIDTH)&&(X>=0)&&((Y-i)>=0)){
        i++;
    }
    if((X<MAP_WIDTH)&&((Y-i)<MAP_WIDTH)&&(X>=0)&&((Y-i)>=0)){
        if((binaryBoard.c_binaryBoard[X][Y-i]!=BLANK_FIELD)&&(binaryBoard.c_binaryBoard[X][Y-i]!=c_figureColor)){
            c_possibleCaptures.push_back(boardCoordinatesToIndex(Y-i,X));
        }
    }
    i=1;
    while((binaryBoard.c_binaryBoard[X+i][Y]==BLANK_FIELD)&&((X+i)<MAP_WIDTH)&&(Y<MAP_WIDTH)&&((X+i)>=0)&&(Y>=0)){
        i++;
    }
    if(((X+i)<MAP_WIDTH)&&(Y<MAP_WIDTH)&&((X+i)>=0)&&(Y>=0)){
       if((binaryBoard.c_binaryBoard[X+i][Y]!=BLANK_FIELD)&&(binaryBoard.c_binaryBoard[X+i][Y]!=c_figureColor)){
            c_possibleCaptures.push_back(boardCoordinatesToIndex(Y,X+i));
        } 
    }
    i=1;
    while((binaryBoard.c_binaryBoard[X-i][Y]==BLANK_FIELD)&&((X-i)<MAP_WIDTH)&&(Y<MAP_WIDTH)&&((X-i)>=0)&&(Y>=0)){
        i++;
    }
    if(((X-i)<MAP_WIDTH)&&(Y<MAP_WIDTH)&&((X-i)>=0)&&(Y>=0)){
       if((binaryBoard.c_binaryBoard[X-i][Y]!=BLANK_FIELD)&&(binaryBoard.c_binaryBoard[X-i][Y]!=c_figureColor)){
            c_possibleCaptures.push_back(boardCoordinatesToIndex(Y,X-i));
        } 
    }
}
