#include <iostream>
using namespace std;
#include "game.h"


void main()
{
	Game myGame =  Game();
	myGame.InitChessBoard();
	myGame.Run();
}

void main02()
{
	int i,j;
	cin >> i>>j;
	cout << i<<j;
	system("pause");
}