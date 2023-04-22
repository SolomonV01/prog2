#include "../lib/game.h"
#include <iostream>
#include <stdexcept>

BaseGame::BaseGame(){
    this->board = new Board(HEIGHT, WIDTH);
    this->board->init(SHIP_COUNT);
}

BaseGame::~BaseGame() {
    delete this->board;
}

int BaseGame::run()
{
    if(this->solve() != SHIP_COUNT)
    {
        throw std::runtime_error("Failed, Not Enough Ships Found");
    }
    auto move_count = this->board->get_move_count();
    if(move_count == 0)
    {
       throw std::runtime_error("Failed, No Moves Made But Ships Found");
    }
    return move_count;
}

