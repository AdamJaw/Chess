#include "pawn.hpp"
#include "board.hpp"
#include <array>
#include "converter.hpp"

Pawn::Pawn(int figureColor, int Y, int X){
    c_classType=1;
    c_figureColor=figureColor;
    c_positionX=X;
    c_positionY=Y;
    c_firstMove = true;
    c_possibleMoves.clear();
    c_possibleCaptures.clear();
}

/*void Pawn::makeListOfPossibleMoves(std::array<std::array<Chessman*,MAP_WIDTH>,MAP_WIDTH> &board){
    c_possibleMoves.clear();
    if(c_firstMove==false){
        if(c_figureColor==1){ //blackPawn==1
            if(board.at(c_positionY+1).at(c_positionX)==nullptr){
                c_possibleMoves.push_back(boardCoordinatesToIndex(c_positionY+1,c_positionX));
            }
        }
        if(c_figureColor==0){ //whitePawn==0
            if(board.at(c_positionY-1).at(c_positionX)==nullptr){
                c_possibleMoves.push_back(boardCoordinatesToIndex(c_positionY-1,c_positionX));
            }
        }
    }
    if(c_firstMove==true){
        if(c_figureColor==1){ //blackPawn==1
            for(int i=1;i<3;i++){
                if(board.at(c_positionY+i).at(c_positionX)==nullptr){
                    c_possibleMoves.push_back(boardCoordinatesToIndex(c_positionY+i,c_positionX));
                }
                if(board.at(c_positionY+i).at(c_positionX)!=nullptr){
                    break;
                }
            }
        }
        if(c_figureColor==0){ //whitePawn==0
            for(int i=1;i<3;i++){
                if(board.at(c_positionY-i).at(c_positionX)==nullptr){
                    c_possibleMoves.push_back(boardCoordinatesToIndex(c_positionY-i,c_positionX));
                }
                if(board.at(c_positionY-i).at(c_positionX)!=nullptr){
                    break;
                }
            }
        }
        c_firstMove=false;
    }
}

*/