#ifndef _GAME_H_
#define _GAME_H_

#include <string>

#define BOARD_SIZE 15+1

struct Position
{
	int x;
	int y;
};
enum player { White_Player, Black_Player };
class Game
{
public:
	Game();
	~Game();
	void InitChessBoard();
	int Run();

private:
//	void InitChessBoard();
	void PrintChessBoard();
	void ChangeChessPlayer();
	int DownChessPiece(const Position& pos);
	int JudgeResult(const Position& pos);
	int JudgeResult01(const Position& pos);
private:
	std::string player1_;
	std::string player2_;
	enum player Who_playChess;
	char chess_board_[BOARD_SIZE][BOARD_SIZE];
};
#endif // _GAME_H_

