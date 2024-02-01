#include "board.hpp"
#include <iostream>

Board::Board(){
    c_texture.loadFromFile("../img/chess.png");
    makeBoardWithoutFigures();
    assignDefaultPointersForBoard();
    assignDefaultFigureValues();
    c_playerTurn=0; // Equal zero means that white pieces start, otherwise 1 is black pieces
    c_isPieceSelected=false; // By default no piece is chosen
}

void Board::makeBoardWithoutFigures(){
    int counter=0;
    for(int i=0;i<MAP_WIDTH;i++){
        for(int j=0;j<MAP_WIDTH;j++){
            counter++;
            c_blankFields[i][j].setSize(sf::Vector2f(TILE_WIDTH,TILE_WIDTH));
            c_blankFields[i][j].setPosition(sf::Vector2f(TILE_WIDTH*i,TILE_WIDTH*j));
            if(counter%2==0){
                c_blankFields[i][j].setFillColor(sf::Color(119,149,86,255));
            }else c_blankFields[i][j].setFillColor(sf::Color(235,236,208,255));
        }
        counter++;
    }
}

void Board::assignDefaultPointersForBoard(){
    for(int i=0;i<MAP_WIDTH;i++){
        for(int j=0;j<MAP_WIDTH;j++){
            c_board[i][j]=nullptr;
        }
    }
    Chessman* array_1[MAP_WIDTH] = {new Rook(0), new Knight(0), new Bishop(0), new Queen(0), new King(0), new Bishop(0), new Knight(0), new Rook(0)}; 
    for(int i=0;i<MAP_WIDTH;i++){
        c_board[i][MAP_WIDTH-1]=array_1[i];
    }
    Chessman* array_2[MAP_WIDTH] = {new Pawn(0,0), new Pawn(0,0), new Pawn(0,0), new Pawn(0,0), new Pawn(0,0), new Pawn(0,0), new Pawn(0,0), new Pawn(0,0)};
    for(int i=0;i<MAP_WIDTH;i++){
        c_board[i][MAP_WIDTH-2]=array_2[i];
    }
    Chessman* array_3[MAP_WIDTH] = {new Rook(1), new Knight(1), new Bishop(1), new Queen(1), new King(1), new Bishop(1), new Knight(1), new Rook(1)}; 
    for(int i=0;i<MAP_WIDTH;i++){
        c_board[i][0]=array_3[i];
    }
    Chessman* array_4[MAP_WIDTH] = {new Pawn(1,1), new Pawn(1,1), new Pawn(1,1), new Pawn(1,1), new Pawn(1,1), new Pawn(1,1), new Pawn(1,1), new Pawn(1,1)};
    for(int i=0;i<MAP_WIDTH;i++){
        c_board[i][1]=array_4[i];
    }
}

void Board::assignDefaultFigureValues(){
    for(int i=0;i<MAP_WIDTH;i++){
        for(int j=0;j<MAP_WIDTH;j++){
            c_figureFields[i][j].setSize(sf::Vector2f(TILE_WIDTH,TILE_WIDTH));
            c_figureFields[i][j].setPosition(sf::Vector2f(TILE_WIDTH*i,TILE_WIDTH*j));
            c_figureFields[i][j].setTexture(&c_texture);
            if(c_board[i][j]!=nullptr){
                c_figureFields[i][j].setFillColor(sf::Color(255,255,255,255));
                //c_figureFields[i][j].setTexture(&c_texture);
                sf::Vector2u textureSize = c_texture.getSize();
                textureSize.x /= 6;
                textureSize.y /= 2;
                switch (c_board[i][j]->c_classType){
                    case 0:
                        if(c_board[i][j]->c_figureColor==1){//black==1
                            c_figureFields[i][j].setTextureRect(sf::IntRect(textureSize.x*5,textureSize.y*1,textureSize.x,textureSize.y));
                        }
                        if(c_board[i][j]->c_figureColor==0){//white==0
                            c_figureFields[i][j].setTextureRect(sf::IntRect(textureSize.x*5,textureSize.y*0,textureSize.x,textureSize.y));
                        }
                    c_texture.setSmooth(true);
                    break;
                    case 1:
                    if(c_board[i][j]->c_figureColor==1){//black==1
                            c_figureFields[i][j].setTextureRect(sf::IntRect(textureSize.x*2,textureSize.y*1,textureSize.x,textureSize.y));
                        }
                        if(c_board[i][j]->c_figureColor==0){//white==0
                            c_figureFields[i][j].setTextureRect(sf::IntRect(textureSize.x*2,textureSize.y*0,textureSize.x,textureSize.y));
                        }
                    c_texture.setSmooth(true);
                    break;
                    case 2:
                    if(c_board[i][j]->c_figureColor==1){//black==1
                            c_figureFields[i][j].setTextureRect(sf::IntRect(textureSize.x*3,textureSize.y*1,textureSize.x,textureSize.y));
                        }
                        if(c_board[i][j]->c_figureColor==0){//white==0
                            c_figureFields[i][j].setTextureRect(sf::IntRect(textureSize.x*3,textureSize.y*0,textureSize.x,textureSize.y));
                        }
                    c_texture.setSmooth(true);
                    break;
                    case 3:
                    if(c_board[i][j]->c_figureColor==1){//black==1
                            c_figureFields[i][j].setTextureRect(sf::IntRect(textureSize.x*4,textureSize.y*1,textureSize.x,textureSize.y));
                        }
                        if(c_board[i][j]->c_figureColor==0){//white==0
                            c_figureFields[i][j].setTextureRect(sf::IntRect(textureSize.x*4,textureSize.y*0,textureSize.x,textureSize.y));
                        }
                    c_texture.setSmooth(true);
                    break;
                    case 4:
                    if(c_board[i][j]->c_figureColor==1){//black==1
                            c_figureFields[i][j].setTextureRect(sf::IntRect(textureSize.x*1,textureSize.y*1,textureSize.x,textureSize.y));
                        }
                        if(c_board[i][j]->c_figureColor==0){//white==0
                            c_figureFields[i][j].setTextureRect(sf::IntRect(textureSize.x*1,textureSize.y*0,textureSize.x,textureSize.y));
                        }
                    c_texture.setSmooth(true);
                    break;
                    case 5:
                    if(c_board[i][j]->c_figureColor==1){//black==1
                            c_figureFields[i][j].setTextureRect(sf::IntRect(textureSize.x*0,textureSize.y*1,textureSize.x,textureSize.y));
                        }
                        if(c_board[i][j]->c_figureColor==0){//white==0
                            c_figureFields[i][j].setTextureRect(sf::IntRect(textureSize.x*0,textureSize.y*0,textureSize.x,textureSize.y));
                        }
                    c_texture.setSmooth(true);
                    break;
                }
            }
            if(c_board[i][j]==nullptr){
                c_figureFields[i][j].setFillColor(sf::Color(255,255,255,0));
            }
        }
    }
}

void Board::setActualPositionOfMouse(sf::Vector2i MousePos){
    c_mousePos.x = (MousePos.x/TILE_WIDTH);
    c_mousePos.y = (MousePos.y/TILE_WIDTH);
}

bool Board::setActualPiece(){
    if(c_board[c_mousePos.x][c_mousePos.y]!=nullptr){
        if(c_playerTurn == c_board[c_mousePos.x][c_mousePos.y]->c_figureColor){
            c_actualPiece.x = c_mousePos.x;
            c_actualPiece.y = c_mousePos.y;
            return true; // There was a piece on that coordinates
        }
    }
    return false; //Error: There was no piece on that position
}

void Board::setActualBoardPosition(){
    if(c_board[c_mousePos.x][c_mousePos.y]==nullptr){
        c_atualPosition.x = c_mousePos.x;
        c_atualPosition.y = c_mousePos.y;
    }
}

void Board::movePiece(Position targetPosition){
    c_figureFields[targetPosition.x][targetPosition.y].setFillColor(c_figureFields[c_actualPiece.x][c_actualPiece.y].getFillColor());
    c_figureFields[c_actualPiece.x][c_actualPiece.y].setFillColor(sf::Color(255,255,255,0));
    c_figureFields[targetPosition.x][targetPosition.y].setTextureRect(c_figureFields[c_actualPiece.x][c_actualPiece.y].getTextureRect());
    c_board[targetPosition.x][targetPosition.y] = c_board[c_actualPiece.x][c_actualPiece.y];
    c_board[c_actualPiece.x][c_actualPiece.y] = nullptr;
}
