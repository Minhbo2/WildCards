#pragma once
#include "pch.h"
#include <string>
#include <vector>
#include <list>
#include <utility>
#include <ctime> 
#include <cstdlib> 


using FString = std::string;
#define FVector std::vector
#define FList std::list



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
	FList<FCard> GetMyDeck() const { return MyDeck; }
	FCard GetTopCardFromDeck();

	void Reset();
	FList<FCard> GetShuffleDeck();


private:

	FVector<FCard> MainDeck;
	FList<FCard> MyDeck;
	void CreateDeck();
};