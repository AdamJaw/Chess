#include "binaryboard.hpp"

BinaryBoard::BinaryBoard(){

    for(int i=0;i<MAP_WIDTH;i++){
        for(int j=0;j<MAP_WIDTH;j++){
            c_binaryBoard[i][j] = BLANK_FIELD; // field without a piece
        }
    }

    for(int i=0;i<MAP_WIDTH;i++){
        c_binaryBoard[i][MAP_WIDTH-1] = 0; // white pieces
        c_binaryBoard[i][MAP_WIDTH-2] = 0;
        c_binaryBoard[i][0] = 1; // black pieces
        c_binaryBoard[i][1] = 1;
    }
}

void BinaryBoard::moveBinaryPiece(int PieceX, int PieceY, int FieldX, int FieldY){
    c_binaryBoard[FieldX][FieldY] = c_binaryBoard[PieceX][PieceY];
    c_binaryBoard[PieceX][PieceY] = BLANK_FIELD;
}
