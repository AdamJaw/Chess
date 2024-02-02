#include "binaryboard.hpp"

BinaryBoard::BinaryBoard(){

    for(int i=0;i<MAP_WIDTH;i++){
        for(int j=0;j<MAP_WIDTH;j++){
            c_binaryBoard[j][i] = BLANK_FIELD; // field without a piece
        }
    }

    for(int i=0;i<MAP_WIDTH;i++){
        c_binaryBoard[MAP_WIDTH-1][i] = 0; // white pieces
        c_binaryBoard[MAP_WIDTH-2][i] = 0;
        c_binaryBoard[0][i] = 1; // black pieces
        c_binaryBoard[1][i] = 1;
    }
}

void BinaryBoard::moveBinaryPiece(int PieceX, int PieceY, int FieldX, int FieldY){
    c_binaryBoard[FieldY][FieldX] = c_binaryBoard[FieldY][PieceX];
    c_binaryBoard[FieldY][PieceX] = BLANK_FIELD;
}
