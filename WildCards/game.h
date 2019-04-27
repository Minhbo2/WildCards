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


	bool IsGameWon() const { return bGameWon; }
	
	void NewRound();
	void DealCard(FPlayer &);
	void Exchange(FPlayer &);
	void Score();
	void AddToLobby(FPlayer);
	
		


private:

	FDeck MyDeck;
	FVector<FPlayer> Lobby;

	bool bGameWon;

	bool WantToExchange();
	void PrintPlayerHand(FPlayer);
	void PrintRoundSummary(FPlayer);
};
