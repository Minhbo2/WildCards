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
	FCard(int, FString, ECardType);
	~FCard();
	

	int CardValue;
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

	int GetAmountRemaind() const { return MyDeck.size(); }
	FVector<FCard> GetMyDeck() const { return MyDeck; }
	FCard GetTopCardFromDeck();

	void Reset();
	void ShuffleDeck();


private:

	FVector<FCard> MainDeck;
	FVector<FCard> MyDeck;
	void CreateDeck();
};