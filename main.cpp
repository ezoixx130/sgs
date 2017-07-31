#include"game.h"
#include"person.h"

int main(int argc,char* argv[])
{
	Game maingame;
	for(int i=0;i<maingame.deck.size();++i)
	{
		cout << maingame.deck.card[i] << endl;
	}
	return 0;
}
