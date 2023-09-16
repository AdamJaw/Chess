#include "board.hpp"

Board::Board(){
    c_texture.loadFromFile("chess.png");
    makeBoardWithoutFigures();
    for(int i=0;i<MAP_WIDTH;i++){
        for(int j=0;j<MAP_WIDTH;j++){
            c_board[i][j]=nullptr;
        }
    }
    assignDefaultFigureValues();
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

void Board::assignDefaultFigureValues(){
    for(int i=0;i<MAP_WIDTH;i++){
        for(int j=0;j<MAP_WIDTH;j++){
            c_figureFields[i][j].setSize(sf::Vector2f(TILE_WIDTH,TILE_WIDTH));
            c_figureFields[i][j].setPosition(sf::Vector2f(TILE_WIDTH*i,TILE_WIDTH*j));
            if(c_board[i][j]!=nullptr){
                c_figureFields[i][j].setFillColor(sf::Color(255,255,255,255));
                c_figureFields[i][j].setTexture(&c_texture);
                sf::Vector2u textureSize = c_texture.getSize();
                textureSize.x /= 6;
                textureSize.y /= 2;
                switch (c_board[i][j]->c_classType){
                    case 1:
                    c_figureFields[i][j].setTextureRect(sf::IntRect(textureSize.x*3,textureSize.y*1,textureSize.x,textureSize.y));
                    c_texture.setSmooth(true);
                    break;
                }
            }
            if(c_board[i][j]==nullptr){
                c_figureFields[i][j].setFillColor(sf::Color(255,255,255,0));
            }
            //c_figureFields[i][j].setTexture(&c_texture);
            /*switch (c_board[i][j]->c_classType){
                case 1:
                c_figureFields[i][j].setTexture(&c_texture);
                break;
                default:
                c_figureFields[i][j].setTexture(&c_texture);
                break;
            }*/
        }
    }
}