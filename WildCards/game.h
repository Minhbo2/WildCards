/*
	SUMMARY: 
	game will will only contain logics of the game.
	in and out put stream will be handle by this class
*/



#pragma once
#include "pch.h"
#include <string>
#include "deck.h"
#include "player.h"


class FGame
{


public:

	FGame();
	~FGame();


	int PlayersInLobby() const { return Lobby.size(); }
	bool IsGameWon() const { return bGameWon; }
	
	void NewRound();
	void Exchange(FPlayer &);
	void Score();
	void AddToLobby(FPlayer);
	void DealToAll();
		


private:

	bool bGameWon;
	FDeck MyDeck;
	FList<FPlayer> Lobby;

	void DealCards(FPlayer &);
	bool WantToExchange();
	void PrintPlayerHand(FPlayer);
	void PrintRoundSummary(FPlayer);
};
