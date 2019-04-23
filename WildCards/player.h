#pragma once
#include "deck.h"
#include <map>


#define TMap std::map



class FPlayer
{

public:

	FPlayer();
	FPlayer(FString);
	~FPlayer();


	int GetRoundWon() const { return RoundWon; }
	int GetNumCardsHold() const { return Hand.size(); }
	void AddToRoundWon() { RoundWon++; }
	TMap<int, FCard> GetCardsInHand() const { return Hand; }
	void DiscardHand() { Hand.clear(); };
	FString GetName() const { return PlayerName; }

	void AddToHand(int, FCard);
	void CardToRemove(int);
	bool HaveCardAt(int);
	int TotalScore();


private:

	FString PlayerName;
	int RoundWon;
	TMap<int, FCard> Hand;
};