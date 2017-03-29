#include <iostream>
using namespace std;
#include "game.h"


void main()
{
	Game myGame =  Game();
	myGame.InitChessBoard();
	myGame.Run();
}








void main03()
{
	char a = 'a';
	cout <<(int)a << endl;
	system("pause");
}
void main02()
{
	int i,j;
	cin >> i>>j;
	cout << i<<j;
	system("pause");
}

void main01()
{
	char ch;
	ch = 1;
//	cout << ch << endl;
	printf("%d",ch);
	system("pause");
}