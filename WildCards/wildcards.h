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

// get return from user input
template<typename T >
T GetUserInput(FString OutString)
{
	T ReturnInput;
	cout << OutString << endl;
	cin >> ReturnInput;
	return ReturnInput;
};

// checking for correct input
template<class T, class J>
bool IsCorrectInput(T InputType, J ExpectType)
{
	return (typeid(InputType) == typeid(ExpectType));
};