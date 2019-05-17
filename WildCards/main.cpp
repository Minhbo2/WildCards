// WildCards.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "game.h"




int main()
{
	FGame Game = FGame();
	Game.RunGame();
	
	return 0;
}





//TODO: things to add
/*


something to consider: what happen if multiple players have the same score? One suggestion to handle this case is to have a system to check if there are more than 1 player with the same score in FGame::Score(), we have 2 approaches: those with the same highest score will won the round, `OR PREFERABLY` *deal hand again for those with the same highest score until there is a clear winner for this round.*

*/