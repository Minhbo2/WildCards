// WildCards.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <list>
#include <string>
#include <utility>
#include "game.h"



// main is only responsible for running the game loop until the game is finish. 
// game state will be handle by FGame class


int main()
{

	FGame Game = FGame();
	FPlayer Player = FPlayer("Player1");
	FPlayer Player1 = FPlayer("Player2");
	Game.AddToLobby(Player);
	Game.AddToLobby(Player1);
	
	Game.NewRound();
	Game.DealCard(Player);
	Game.Exchange(Player);

	return 0;
}

//TODO: things to add
/*

Adding to FGame::Score()
{
   adding to round won for the player with highest score
  also check to see which player has won 10 round
  if there is a player won 10 round, gameiswon = true
} (edited)


something to consider: what happen if multiple players have the same score? One suggestion to handle this case is to have a system to check if there are more than 1 player with the same score in FGame::Score(), we have 2 approaches: those with the same highest score will won the round, `OR PREFERABLY` *deal hand again for those with the same highest score until there is a clear winner for this round.*


main.cpp will handle intro and tracking players in lobby
ask for how many people will be playing. each player will take turns to insert name, main will add player to FGame lobby.
*/