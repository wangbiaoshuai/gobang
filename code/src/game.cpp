#include "game.h"
#include <iostream>
#include <string.h>

using namespace std;

Game::Game() :
	player1_("A"),
	player2_("B")
{
	for (register int i = 0; i < BOARD_SIZE; i++)
	{
		memset(chess_board_[i], 0, sizeof(char) * BOARD_SIZE);
	}
}

Game::~Game()
{
   cout<<"just for test"<<endl;OB
}
void Game::InitChessBoard()
{
	for (register int i = 0; i < BOARD_SIZE; i++)
	{
		 chess_board_[0][i] = i+'0';
	}
	
	for (register int i = 1; i < BOARD_SIZE; i++)
	{		
		chess_board_[i][0] = i+'0';
		for (register int j = 1; j < BOARD_SIZE; j++)
		{
			chess_board_[i][j] = '*';
		}
	}
}
void Game::PrintChessBoard()
{
	for (register int i = 0; i < BOARD_SIZE; i++)
	{		
		for (register int j = 0; j < BOARD_SIZE; j++)
		{
			cout<<chess_board_[i][j]<<" " ;
		}
		cout << endl;
	}
}
int Game::DownChessPiece(const char piece, const Position& pos)
{

}
int Game::JudgeResult(const Position& pos)
{

}

int Game::Init()
{

}
int Game::Run()
{
}

