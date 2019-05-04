#pragma once

#include "pch.h"
#include <string>
#include <iostream>
#include "deck.h"
#include "player.h"

using namespace std;

class FWildCards
{
public:
	FWildCards();
	~FWildCards();

	bool IsGameWon() const { return bGameWon; }

	void NewRound();
	void Exchange(FPlayer &);
	void Score(FList<FPlayer> &);
	void DealToAll(FList<FPlayer> &);

private:

	bool bGameWon;
	FDeck MyDeck;

	FPlayer Leader;

	void DealCards(FPlayer &);
	bool WantToExchange();
	void PrintPlayerHand(FPlayer);
	void PrintRoundSummary(FPlayer);
};