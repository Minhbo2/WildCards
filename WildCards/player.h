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
	int GetTotalScore();


private:

	FString PlayerName;
	int RoundWon;

	//Why map?:
	/*
	limitation of simple array: unable to delete an element
	order is important, list is out of the question
	vetor will require memory allocation everytime performing insertion and deletion
	that leaves only map
	*/
	TMap<int, FCard> Hand;
};