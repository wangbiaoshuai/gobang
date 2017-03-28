#include "game.h"
#include <iostream>
#include <string.h>

using namespace std;

//Game::Game() :
//	player1_("A"),
//	player2_("B")
Game::Game():
	Who_playChess(White_Player)
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

void Game::ChangeChessPlayer()
{
	if (Who_playChess == White_Player)
	{
		Who_playChess = Black_Player;
	}
	else
	{
		Who_playChess = White_Player;
	}
}

int Game::DownChessPiece(const Position& pos)
{
	if (pos.x < 0 || pos.x >= BOARD_SIZE || 
		pos.y < 0 || pos.y >= BOARD_SIZE ||
		chess_board_[pos.x][pos.y] != '*')
	{
		cout << "please input the correct position:" << endl;
		return 0;
	}

	if (Who_playChess == White_Player)
	{
		chess_board_[pos.x][pos.y] = 'O';
	}
	else
	{
		chess_board_[pos.x][pos.y] = 'X';
	}	
	return 1;
}

int Game::JudgeResult(const Position& pos)
{
	int x = pos.x;
	int y = pos.y;
	int count = 1;
	char cur = chess_board_[x][y];

	//竖直方向
	      //垂直向上
	for (int i = x, j = y - 1; j > 0 && count <= 5; j--)
	{
		if (chess_board_[i][j] == cur)
		{
			count++;
		}
		else
		{
			break;
		}
	}
	if (count == 5)
	{
		return 1;
	}
	      //垂直向下
	for (int i = x, j = y + 1; j < BOARD_SIZE && count <= 5; j++)
	{
		if (chess_board_[i][j] == cur)
		{
			count++;
		}
		else
		{
			break;
		}
	}
	if (count == 5)
	{
		return 1;
	}

	
	//水平方向
	       //水平向左
	count = 1;
	for (int i = x - 1, j = y; i > 0 && count <= 5; i--)
	{
		if (chess_board_[i][j] == cur)
		{
			count++;
		}
		else
		{
			break;
		}
	}
	
	if (count == 5)
	{
		return 1;
	}
	        //水平向右
	for (int i = x + 1, j = y; i < BOARD_SIZE && count <= 5; i++)
	{
		if (chess_board_[i][j] == cur)
		{
			count++;
		}
		else
		{
			break;
		}
	}
	
	if (count == 5)
	{
		return 1;
	}

	//↙↗对角线方向
	       //往↙方向
	count = 1;
	for (int i = x-1, j = y+1; i > 0 && j < BOARD_SIZE; i--, j++)
	{
		if (chess_board_[i][j] == cur)
		{
			count++;
		}
		else
		{
			break;
		}
	}
	if (count == 5)
	{
		return 1;
	}
		//往↗方向
	for (int i = x+1, j = y-1; i < BOARD_SIZE && j > 0; i++, j--)
	{
		if (chess_board_[i][j] == cur)
		{
			count++;
		}
		else
		{
			break;
		}
	}
	if (count == 5)
	{
		return 1;
	}


	//↖↘对角线方向
	   //往↖方向
	count = 1;
	for (int i = x - 1, j = y - 1; i > 0 && j > 0; i--, j--)
	{
		if (chess_board_[i][j] == cur)
		{
			count++;
		}
		else
		{
			break;
		}
	}
	if (count == 5)
	{
		return 1;
	}
	 //往↘方向
	for (int i = x + 1, j = y + 1; i <BOARD_SIZE  && j > BOARD_SIZE; i++, j++)
	{
		if (chess_board_[i][j] == cur)
		{
			count++;
		}
		else
		{
			break;
		}
	}
	if (count == 5)
	{
		return 1;
	}
	return 0;
}


int Game::Run()
{
	Position pos;
	char ch;
	do {
		PrintChessBoard();
		cout << "please input the position such as 1,2 :" << endl;
		do {
		//	fflush(stdin);
			cin >> pos.x >> ch >> pos.y;
			//todo  考虑缓存区，当输入char型数据时候
			//cin函数会终止，不清空缓存器的话会一直循环。。。。
		//	cin >> pos.x;
		//	fflush(stdin);
		//	cin.clear();
		//	cin.sync();
		//	cin>> pos.y;
		} while (DownChessPiece(pos) == 0);
		ChangeChessPlayer();
	} while (JudgeResult(pos) == 0);
	PrintChessBoard();
	ChangeChessPlayer();
	cout <<(( Who_playChess == 0)? "White player":"Black player")<<" win the game !" << endl;
	system("pause");
	return 1;

}

