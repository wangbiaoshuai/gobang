#include "game.h"
#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

Game::Game():
	player1_("A"),
	player2_("B"),
	Who_playChess(White_Player)
{
	for (register int i = 0; i < BOARD_SIZE; i++)
	{
		memset(chess_board_[i], 0, sizeof(char) * BOARD_SIZE);
	}
}

Game::~Game()
{
}
void Game::InitChessBoard()
{
	cout << "model 1:player VS player" << endl;
	cout << "model 2:player VS computer" << endl;
	cout << "please select mode:1" << endl;
	cout << "please enter name of player1:";
	cin >> player1_;
	cout << "please enter name of player2:";
	cin >> player2_;
	char ch;
	cout << "Enter game(y/n):";
	cin >> ch;
	if (ch == 'n')
	{
		return;
	}

	for (register int i = 0; i < BOARD_SIZE; i++)
	{
		// chess_board_[0][i] = i+'0';
		chess_board_[0][i] = i ;
	}
	
	for (register int i = 1; i < BOARD_SIZE; i++)
	{		
		// chess_board_[i][0] = i+'0';
		chess_board_[i][0] = i;
		for (register int j = 1; j < BOARD_SIZE; j++)
		{
			chess_board_[i][j] = '*';
		}
	}
}
void Game::PrintChessBoard()
{
	system("cls");
	for (register int i = 0; i < BOARD_SIZE; i++)
	{		
		for (register int j = 0; j < BOARD_SIZE; j++)
		{			
			if(i==0||j==0)
			{
			//	printf("%2d ", chess_board_[i][j]);		
				cout <<setiosflags(ios::right)<< setw(3)<<(int) chess_board_[i][j];
			}
			else
			{
			//	cout << chess_board_[i][j] << "  ";
				cout << setw(3) << chess_board_[i][j];
			}

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
		cout << ((Who_playChess == 0) ? player1_+"  O" : player2_+"  X")
			 <<" please input the correct position:" << endl;
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

int Game::JudgeResult01(const Position& pos)
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
int Game::JudgeResult(const Position& pos)
{
	int x = 0;
	int y = 0;
	int count = 0;
	char cur = chess_board_[pos.x][pos.y];
	cout << cur << endl;
	int i = 1;
	for (i; i <= 4; i++)
	{

		count = 1;
		x = pos.x;
		y = pos.y;
		do {
				switch (i)
				{
					case 1:
						y++;
						break;
					case 2:
						x--;
						break;
					case 3:
						x--;
						y++;
						break;
					case 4:
						x--;
						y--;
						break;
					default:
						;
				}
				if (chess_board_[x][y] == cur)
				{
					cout << cur << endl;
					count++;
				}
				else 
				{
					break;
				}
		} while (count!=5);
		
		x = pos.x;
		y = pos.y;
		while (count != 5) 
		{
			switch (i)
			{
			case 1:
				y--;
				break;
			case 2:
				x++;
				break;
			case 3:
				x++;
				y--;
				break;
			case 4:
				x++;
				y++;
				break;
			default:
				;
			}
			if (chess_board_[x][y] == cur)
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
	}
	
	return  0;
}

int Game::Run()
{
	Position pos;
	char ch;
	do {
		PrintChessBoard();
		cout << ((Who_playChess == 0) ? player1_+"  O" : player2_+"  X")
			 << "  please input the position such as 1,2 :" << endl;
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
	cout <<(( Who_playChess == 0)? player1_:player2_)<<" win the game !" << endl;
	system("pause");
	return 1;

}

