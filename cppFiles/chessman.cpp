#include "chessman.hpp"
#include "board.hpp"

/*int Chessman::moveFigure(int Y, int X, std::array<std::array<Chessman*,MAP_WIDTH>,MAP_WIDTH> &board){
    if(board[Y][X]!=nullptr){
        if(this->c_figureColor==board[Y][X]->c_figureColor){
            return 1; //Ally on the requested field
        }
    }
    if((X>MAP_WIDTH)||(Y>MAP_WIDTH)||(X<0)||(Y<0)){
        return 2; //Outside of the board
    }
    
    for(unsigned int i=0;i<this->c_possibleMoves.size();i++){
        if(this->c_possibleMoves[i]==boardCoordinatesToIndex(Y,X)){
            board[Y][X] = board[this->c_positionY][this->c_positionX];
            board[this->c_positionY][this->c_positionX]=nullptr;
            this->c_positionY=Y;
            this->c_positionX=X;
            return 3; //Figure moved correctly
        }
    }
    return 4; //Requested field is not a possible move
}*/