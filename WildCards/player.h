#pragma once
#include "deck.h"
#include <map>


#define TMap std::map



class FPlayer
{

public:

	FPlayer();
	~FPlayer();


	int GetRoundWon() const { return RoundWon; }
	int GetNumCardsHold() const { return Hand.size(); }
	FCard GetCard(int Index) const { return Hand.at(Index); }
	void AddToRoundWon() { RoundWon++; }


	void AddToHand(int, FCard);
	void CardToRemove(int);
	bool HaveCardAt(int);


private:


	int RoundWon;
	TMap<int, FCard> Hand;
};