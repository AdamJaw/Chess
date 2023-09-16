#include "chessman.hpp"
#include "pawn.hpp"
//#include <array>
//#include <iostream>
#include <SFML/Graphics.hpp>
#include "board.hpp"

/*int main(){
    sf::RenderWindow window(sf::VideoMode(800,800),"Chess",sf::Style::Close);
    while(window.isOpen()){
        sf::Event evnt;
        while(window.pollEvent(evnt)){
            if(evnt.type == sf::Event::Closed){
                window.close();
            }
        }
        window.display();
    }
    std::array<std::array<Chessman*,8>,8> board;
    for(int i=0;i<MAP_WIDTH;i++){
        for(int j=0;j<MAP_WIDTH;j++){
            board[i][j]=nullptr;
        }
    }
    //std::cout << board[0][0];
    board.at(0).at(0) = new Pawn(1,0,0);
    //std::cout << board[0][0];
    //board.at(2).at(0) = new Pawn(0,2,0);
    //board[0][0]->c_possibleMoves.push_back(10);

    for(int i=0;i<MAP_WIDTH;i++){
        for(int j=0;j<MAP_WIDTH;j++){
            if(board[i][j]==nullptr){
                std::cout << 0 << ' ';
            }
            else{
                std::cout << 1 << ' ';
            }
        }
        std::cout << std::endl;
    }

    board.at(0).at(0)->makeListOfPossibleMoves(board);
    //std::cout << board[0][0]->c_possibleMoves.size();
    //std::cout << board[1][0];
    //std::cout << board[0][0];

    std::cout << board[0][0]->moveFigure(1,0,board);

    //std::cout << board[1][0];
    //std::cout << board[0][0];
    //std::cout << board[0][0]->c_possibleMoves[0] << std::endl;
    //std::cout << board[0][0]->c_possibleMoves[1];
    std::cout << std::endl;
    for(int i=0;i<MAP_WIDTH;i++){
        for(int j=0;j<MAP_WIDTH;j++){
            if(board[i][j]==nullptr){
                std::cout << 0 << ' ';
            }
            else{
                std::cout << 1 << ' ';
            }
        }
        std::cout << std::endl;
    }
    //std::cout << board[0][0]->c_possibleMoves.size();
    //if(board[0][0]->c_possibleMoves[0]!=(-1)){
    //    std::cout << "PIONEK NA DRODZE!";
    //}
    //if(board.at(0).at(0)->c_classType=="Pawn"){
    //    std::cout << "To pionek!";
    //}
    return 0;
}*/

int main(){
    sf::RenderWindow window(sf::VideoMode(800,800),"Chess",sf::Style::Close);
    Board board;
    board.c_board[0][0] = new Pawn(1,0,0);
    board.assignDefaultFigureValues();
    while(window.isOpen()){
        sf::Event evnt;
        while(window.pollEvent(evnt)){
            if(evnt.type == sf::Event::Closed){
                window.close();
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