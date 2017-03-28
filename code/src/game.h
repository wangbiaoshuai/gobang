#ifndef _GAME_H_
#define _GAME_H_

#include <string>

#define BOARD_SIZE 15+1

struct Position
{
    int x; 
    int y;
};

class Game
{
public:
    Game();
    ~Game();
    int Init();
    int Run();

private:
    void PrintChessBoard();
    int DownChessPiece(const char piece, const Position& pos);
    int JudgeResult(const Position& pos);
    bool IsLegalPos(const Position& pos);
    int JudgeDirectionResult(int direc, const Position& pos);

private:
    std::string player1_;
    std::string player2_;
    char chess_board_[BOARD_SIZE][BOARD_SIZE];
};
#endif // _GAME_H_
