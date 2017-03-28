#include "game.h"
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>

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

void Game::PrintChessBoard()
{
    for(register int i = 0; i < BOARD_SIZE; i++)
    {
        for(register int j = 0; j < BOARD_SIZE; j++)
        {
            if(i == 0)
            {
                printf(" %2d", j);
            }
            else if(j == 0)
            {
                printf(" %2d", i);
            }
            else if(chess_board_[i][j] == 0)
            {
                printf("  *");
            }
            else if(chess_board_[i][j] == 1)
            {
                printf("  O");
            }
            else if(chess_board_[i][j] == 2)
            {
                printf("  X");
            }
        }
        printf("\n");
    }
}

int Game::DownChessPiece(const char piece, const Position& pos)
{
    if(!IsLegalPos(pos))
        return -1;

    if(chess_board_[pos.x][pos.y] != 0)
    {
        return -1;
    }

    if(piece == 'O')
    {
        chess_board_[pos.x][pos.y] = 1;
    }
    else if(piece == 'X')
    {
        chess_board_[pos.x][pos.y] = 2;
    }
    else
    {
        return -1;
    }
    return 0;
}

bool Game::IsLegalPos(const Position& pos)
{
    if(pos.x < 1 || pos.x > 15 || pos.y < 1 || pos.y > 15)
        return false;
    return true;
}

int Game::JudgeDirectionResult(int direc, const Position& pos)
{
    int count = 0;
    char piece = chess_board_[pos.x][pos.y];
    Position next_pos = pos;
    for(register int i = 0; i < 4; i++)
    {
        if(direc == 1)
        {
            next_pos.y++;
        }
        else if(direc == 2)
        {
            next_pos.x++;
        }
        else if(direc == 3)
        {
            next_pos.x++;
            next_pos.y--;
        }
        else if(direc == 4)
        {
            next_pos.x++;
            next_pos.y++;

        }
        if(!IsLegalPos(next_pos))
            break;
        if(chess_board_[next_pos.x][next_pos.y] == piece)
        {
            count++;
        }
        else
        {
            break;
        }
    }
    if(count + 1 == 5)
        return 0;

    next_pos = pos;
    for(register int i = 0; i < 4; i++)
    {
        if(direc == 1)
        {
            next_pos.y--;
        }
        else if(direc == 2)
        {
            next_pos.x--;
        }
        else if(direc == 3)
        {
            next_pos.x--;
            next_pos.y++;
        }
        else if(direc == 4)
        {
            next_pos.x--;
            next_pos.y--;

        }
        if(!IsLegalPos(next_pos))
            break;
        if(chess_board_[next_pos.x][next_pos.y] == piece)
        {
            count++;
        }
        else
        {
            break;
        }
    }
    if(count + 1 == 5)
        return 0;
    return -1;
}

int Game::JudgeResult(const Position& pos)
{
    if(!IsLegalPos(pos))
        return -1;
    for(register int i = 1; i <= 4; i++)
    {
        if(JudgeDirectionResult(i, pos) == 0)
            return 0;
    }
    return -1;
}

int Game::Init()
{
    system("clear");
    string str;
    cout<<"#mode 1: player VS player"<<endl;
    cout<<"#mode 2: player VS computer"<<endl;
    cout<<"please select mode:1"<<endl;
    cout<<"Please enter name of player1:";
    getline(cin, player1_);
    cout<<"Please enter name of player2:";
    getline(cin, player2_);
    cout<<"Enter game(y/n):";
    getline(cin, str);
    if(str != "y" && str != "Y")
    {
        return -1;
    }

    return 0;
}

int Game::Run()
{
    if(Init() != 0)
    {
        cout<<"error: Init failed"<<endl;
        return -1;
    }

    int count = 1;
    string player;
    char piece;

    do
    {
        system("clear");
        Position pos;
        PrintChessBoard();
        if(count % 2 == 1)
        {
            player = player1_;
            piece = 'O';
        }
        else
        {
            player = player2_;
            piece = 'X';
        }
        cout<<"Turn to player "<<player<<", please input the position(x,y):";
        cin>>pos.x; cin>>pos.y;
        while(!IsLegalPos(pos) || DownChessPiece(piece, pos) != 0)
        {
            cout<<"Position error, please enter again:";
            cout.flush();
            cin>>pos.x; cin>>pos.y;
        }

        if(JudgeResult(pos) == 0)
        {
            system("clear");
            PrintChessBoard();
            cout<<"player "<<player<<" win!"<<endl;
            break;
        }

        count++;
    }while(true);
    return 0;
}

