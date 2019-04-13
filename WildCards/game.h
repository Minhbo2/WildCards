#pragma once
#include "pch.h"
#include <string>
#include "deck.h"
#include <map>


#define TMap std::map



class FPlayer
{
public:

	FPlayer();
	~FPlayer();


	short GetRoundWon() const { return RoundWon; }
	short NumCardsHold() const { return Hand.size(); }


	void AddToHand(FCard);
	FCard CardToRemove(short CardIndex);


private:


	short RoundWon;
	TMap<short, FCard> Hand;
};