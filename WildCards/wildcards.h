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

	void NewRound();
	void Exchange(FPlayer &);
	void DealCards(FPlayer &);

private:

	FDeck MyDeck;

	bool WantToExchange();
	void PrintPlayerHand(FPlayer);
	void PrintRoundSummary(FPlayer);
};