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


	int GetRoundWon() const { return RoundWon; }
	int NumCardsHold() const { return Hand.size(); }
	FCard GetCardAt(int CardIndex) const { return Hand.at(CardIndex); }


	void AddToHand(int, FCard);
	void CardToRemove(int CardIndex);


private:


	int RoundWon;
	TMap<int, FCard> Hand;
};




/*===========================================================
======================== GAME =============================
===========================================================*/


class FGame
{


public:

	bool IsGameWon() const { return bGameWon; }

	void ShuffleDeck();
	
	


private:

	bool bGameWon;

};


// TODO: create a game manager(states) for game loop
/*
manage how many player are there in game
method for main to call and execute game states
*/
