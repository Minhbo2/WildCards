#pragma once
#include "pch.h"
#include <string>
#include <vector>
#include <ctime> 
#include <cstdlib> 


using FString = std::string;
#define FVector std::vector



enum class ECardType
{
	Space = 0,
	Club = 1,
	Diamond = 2,
	Heart = 3
};





struct FCard
{
	FCard();
	FCard(short, FString, ECardType);
	~FCard();
	

	short CardValue;
	FString CardName;
	ECardType CardType;
};





//============================================================
// ********************DECK CLASS*****************************
//============================================================

class FDeck
{

public:
	FDeck();
	~FDeck();

	short GetAmountRemainded() const { return MyDeck.size(); }
	FVector<FCard> GetMyDeck() const { return MyDeck; }
	FCard GetTopCardFromDeck();

	void Reset();


private:

	FVector<FCard> MyDeck = FVector<FCard>{5};


	void CreateDeck();
	void ShuffleDeck();
};