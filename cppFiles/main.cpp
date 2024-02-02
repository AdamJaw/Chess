#include <SFML/Graphics.hpp>
#include "converter.hpp"
#include "board.hpp"
#include "binaryboard.hpp"
#include <iostream>

int main(){
    sf::RenderWindow window(sf::VideoMode(800,800),"Chess",sf::Style::Close);
    BinaryBoard binaryBoard;
    Board board;
    /*for(int i=0;i<MAP_WIDTH;i++){
        for(int j=0;j<MAP_WIDTH;j++){
            std::cout << board.c_tableOfFieldsMattedByBlack[i][j];
        }
        std::cout << std::endl;
    }
     for(int i=0;i<MAP_WIDTH;i++){
        for(int j=0;j<MAP_WIDTH;j++){
            std::cout << board.c_tableOfFieldsMattedByWhite[i][j];
        }
        std::cout << std::endl;
    }
   for(int i=0;i<MAP_WIDTH;i++){
        for(int j=0;j<MAP_WIDTH;j++){
            std::cout << board.c_binaryBoard.c_binaryBoard[i][j];
        }
        std::cout << std::endl;
    }*/
    while(window.isOpen()){
        sf::Event evnt;
        while(window.pollEvent(evnt)){
            if(evnt.type == sf::Event::Closed){
                window.close();
            }
            if(evnt.type == sf::Event::MouseButtonPressed){
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                board.setActualPositionOfMouse(mousePos);

                if(board.c_isPieceSelected==true){
                    if(board.c_board[board.c_mousePos.x][board.c_mousePos.y]!=nullptr){
                        if(board.c_playerTurn==board.c_board[board.c_mousePos.x][board.c_mousePos.y]->c_figureColor){
                            board.c_actualPiece.x = board.c_mousePos.x;
                            board.c_actualPiece.y = board.c_mousePos.y;

                            board.c_board[board.c_actualPiece.x][board.c_actualPiece.y]->makeListOfPossibleMoves(binaryBoard,board.c_actualPiece.x,board.c_actualPiece.y);
                            board.c_howManyPossibleMoves = board.c_board[board.c_actualPiece.x][board.c_actualPiece.y]->c_possibleMoves.size();
                            //std::cout<< board.c_howManyPossibleMoves;

                            board.c_board[board.c_actualPiece.x][board.c_actualPiece.y]->makeListOfPossibleCaptures(binaryBoard,board.c_actualPiece.x,board.c_actualPiece.y);
                            board.c_howManyPossibleCaptures = board.c_board[board.c_actualPiece.x][board.c_actualPiece.y]->c_possibleCaptures.size();
                            //std::cout<< board.c_howManyPossibleCaptures;
                        }
                        if(board.c_playerTurn!=board.c_board[board.c_mousePos.x][board.c_mousePos.y]->c_figureColor){
                           board.c_actualEnemyPiece.x = board.c_mousePos.x;
                            board.c_actualEnemyPiece.y = board.c_mousePos.y;
                            for(int i=0;i<board.c_howManyPossibleCaptures;i++){
                                if(board.c_board[board.c_actualPiece.x][board.c_actualPiece.y]->c_possibleCaptures[i] == boardCoordinatesToIndex(board.c_actualEnemyPiece.y,board.c_actualEnemyPiece.x)){
                                    board.movePiece(board.c_actualEnemyPiece);
                                    binaryBoard.moveBinaryPiece(board.c_actualPiece.x,board.c_actualPiece.y,board.c_actualEnemyPiece.x,board.c_actualEnemyPiece.y);
                                    board.c_binaryBoard.moveBinaryPiece(board.c_actualPiece.x,board.c_actualPiece.y,board.c_actualEnemyPiece.x,board.c_actualEnemyPiece.y);
                                    board.c_isPieceSelected=false;
                                    if(board.c_playerTurn==1){
                                    board.c_playerTurn=0;
                                    }else board.c_playerTurn=1;
                                    break;//cannot do if when pointer in movePiece is destroyed
                                }
                            }
                        }
                    }
                    if(board.c_board[board.c_mousePos.x][board.c_mousePos.y]==nullptr){
                        board.c_atualPosition.x = board.c_mousePos.x;
                        board.c_atualPosition.y = board.c_mousePos.y;
                        for(int i=0;i<board.c_howManyPossibleMoves;i++){
                            if(board.c_board[board.c_actualPiece.x][board.c_actualPiece.y]->c_possibleMoves[i] == boardCoordinatesToIndex(board.c_atualPosition.y,board.c_atualPosition.x)){
                                board.movePiece(board.c_atualPosition);
                                binaryBoard.moveBinaryPiece(board.c_actualPiece.x,board.c_actualPiece.y,board.c_atualPosition.x,board.c_atualPosition.y);
                                board.c_binaryBoard.moveBinaryPiece(board.c_actualPiece.x,board.c_actualPiece.y,board.c_atualPosition.x,board.c_atualPosition.y);
                                board.c_isPieceSelected=false;
                                if(board.c_playerTurn==1){
                                    board.c_playerTurn=0;
                                }else board.c_playerTurn=1;
                                break;//cannot do if when pointer in movePiece is destroyed
                            }
                        }
                    }
                }

                if(board.c_isPieceSelected==false){
                    if(board.c_board[board.c_mousePos.x][board.c_mousePos.y]!=nullptr){
                        if(board.c_playerTurn==board.c_board[board.c_mousePos.x][board.c_mousePos.y]->c_figureColor){
                            board.c_actualPiece.x = board.c_mousePos.x;
                            board.c_actualPiece.y = board.c_mousePos.y;
                            board.c_isPieceSelected=true;

                            board.c_board[board.c_actualPiece.x][board.c_actualPiece.y]->makeListOfPossibleMoves(binaryBoard,board.c_actualPiece.x,board.c_actualPiece.y);
                            board.c_howManyPossibleMoves = board.c_board[board.c_actualPiece.x][board.c_actualPiece.y]->c_possibleMoves.size();
                           
                            board.c_board[board.c_actualPiece.x][board.c_actualPiece.y]->makeListOfPossibleCaptures(binaryBoard,board.c_actualPiece.x,board.c_actualPiece.y);
                            board.c_howManyPossibleCaptures = board.c_board[board.c_actualPiece.x][board.c_actualPiece.y]->c_possibleCaptures.size();
                             //std::cout << board.c_board[board.c_actualPiece.x][board.c_actualPiece.y]->c_possibleCaptures.size();
                        }
                    }
                }
                /*sf::Vector2i MousePos = sf::Mouse::getPosition(window);
                board.setActualPositionOfMouse(MousePos);
                if(board.setActualPiece()==true){
                    board.c_board[board.c_actualPiece.x][board.c_actualPiece.y]->makeListOfPossibleMoves(binaryBoard,board.c_actualPiece.x,board.c_actualPiece.y);
                    board.c_howManyForLoops = board.c_board[board.c_actualPiece.x][board.c_actualPiece.y]->c_possibleMoves.size();
                    board.c_isPiecePositionSet=true;
                }
                if(board.c_isPiecePositionSet==true){
                    board.setActualBoardPosition();
                    for(int i=0;i<board.c_howManyForLoops;i++){
                        if(board.c_board[board.c_actualPiece.x][board.c_actualPiece.y]->c_possibleMoves[i] == boardCoordinatesToIndex(board.c_atualPosition.y,board.c_atualPosition.x)){
                            board.movePiece();
                            binaryBoard.moveBinaryPiece(board.c_actualPiece.x,board.c_actualPiece.y,board.c_atualPosition.x,board.c_atualPosition.y);
                            break;//cannot do if when pointer in movePiece is destroyed
                            board.c_isPiecePositionSet=false;
                        }
                    }
                }*/
            }
        }


        window.clear();
        for(int i=0;i<MAP_WIDTH;i++){
            for(int j=0;j<MAP_WIDTH;j++){
                window.draw(board.c_blankFields[i][j]);
            }
        }
        for(int i=0;i<MAP_WIDTH;i++){
            for(int j=0;j<MAP_WIDTH;j++){
                window.draw(board.c_figureFields[i][j]);
            }
        }
        window.display();
    }
    return 0;
}