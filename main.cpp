#include "chessman.hpp"
#include "pawn.hpp"
#include <array>

int maint(){
    std::vector<std::vector<Chessman*>> board;
    board.at(0).at(0) = new Pawn;
    return 0;
}