#include "game.h"
#include <iostream>
#include <string.h>

using namespace std;

Game::Game() :
player1_("A"),
player2_("B")
{
    for(register int i = 0; i < BOARD_SIZE; i++)
    {
        memset(chess_board_[i], 0, sizeof(char) * BOARD_SIZE);
    }
}

Game::~Game()
{
}


