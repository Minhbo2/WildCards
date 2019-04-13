// WildCards.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "game.h"



// main is only responsible for outputting and receive input the game status 


int main()
{

	FGame GameManager = FGame();

	do
	{

		// run game while no1 win 
		/*
			loop:
			*shuffle
			*deal
			*exchange 
			*score
		tracking which player won: 1st to won 5 rounds

		shuffle = deck reset every game
		deal = loop through each player deal 5 cards each from deck
		exchange = player selects up to 5 card to exchange and receive cards until has 5 in hand
		score = add all cards value and whoever has the highest score won the round
		*/


	} while (!GameManager.IsGameWon());

	return 0;
}
