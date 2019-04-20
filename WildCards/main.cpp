// WildCards.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "game.h"



// main is only responsible for running the game loop until the game is finish. 
// game state will be handle by FGame class


int main()
{

	FGame Game = FGame();
	FPlayer Player = FPlayer();
	Game.ShuffleDeck();

	Game.DealCard(Player);
	Game.Exchange(Player);

	return 0;
}


//TODO:
	//cards player need to exchange
	//score