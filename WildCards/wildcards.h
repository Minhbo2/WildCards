#pragma once

#include "pch.h"
#include "deck.h"
#include "player.h"
#include "gihf.h"



class FWildCards
{
public:
	FWildCards();
	~FWildCards();

	void NewDeck();
	void Exchange(FPlayer &);
	void DealCards(FPlayer &);

private:

	FDeck MyDeck;

	bool WantToExchange();
	void PrintPlayerHand(FPlayer);
};