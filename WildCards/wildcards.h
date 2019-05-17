#pragma once

#include "pch.h"
#include <string>
#include <iostream>
#include "deck.h"
#include "player.h"

using namespace std;


//Global static helper function: get correct user input
template<class T >
static T GetUserInput(FString OutString)
{
	T UserInput;
	bool bValid = false;
	while (!bValid)
	{
		cout << OutString << endl;
		cin >> UserInput;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			auto TypeName = typeid(UserInput).name();
			cout << "Please enter correct input of " << TypeName << endl;
		}
		else
			bValid = true;
	}
	return UserInput;
};



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
};