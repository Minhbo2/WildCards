#include "pch.h"
#include <iostream>
#include <string>
#include "game.h"

using namespace std;


FGame::FGame()
{
	MyDeck = FDeck();
}

void FGame::ShuffleDeck()
{
	MyDeck.ShuffleDeck();
}

void FGame::DealCard(FPlayer & CurrentPlayer)
{
	const int MAX_CARD_DEAL = 5;
	int CardsInHand = CurrentPlayer.GetNumCardsHold();


	for (int i = CardsInHand; i < MAX_CARD_DEAL; i++)
	{
		if (MyDeck.GetAmountRemaind() > 0 && !CurrentPlayer.HaveCardAt(i))
		{
			FCard Card = MyDeck.GetTopCardFromDeck();
			CurrentPlayer.AddToHand(i, Card);
		}
	}

	PrintPlayerHand(CurrentPlayer);
}

void FGame::Exchange(FPlayer & CurrentPlayer)
{
	//TODO: DEBUG, doesn't print card# 5 eventhough it still in hand.
	if (WantToExchange())
	{
		cout << "How many cards do you want to exchange? \n";
		string InAnswer;
		getline(cin, InAnswer);
		int NumCard = stoi(InAnswer);
		
		for (int i = 0; i < NumCard; i++)
		{
			//TODO: might b helpful to write template function to handle input from player
			cout << "Select a card#: ";
			string InIndex;
			getline(cin, InIndex);
			int CardIndex = stoi(InIndex);
		
			CurrentPlayer.CardToRemove(CardIndex - 1);
		}
	}

	PrintPlayerHand(CurrentPlayer);
}

bool FGame::WantToExchange()
{
	cout << "Do you want to exchange cards? ";
	cout << "Y/y or N/n \n\n";

	string InAnswer;
	getline(cin, InAnswer);
	cout << endl;

	char Answer = tolower(InAnswer[0]);
	if (Answer == 'y')
		return true;

	return false;
}

void FGame::PrintPlayerHand(FPlayer CurrentPlayer)
{
	//system("CLS");

	int CardsHolding = CurrentPlayer.GetNumCardsHold();
	for (int i = 0; i < CardsHolding; i++)
	{
		if (!CurrentPlayer.HaveCardAt(i)) 
			continue;

		FCard Card = CurrentPlayer.GetCard(i);
		std::string CardType;
		int TypeIndex = int(Card.CardType);

		if (TypeIndex == 0)
			CardType = "Space";
		else if (TypeIndex == 1)
			CardType = "Club";
		else if (TypeIndex == 2)
			CardType = "Diamond";
		else
			CardType = "Heart";

		cout << "Card #" << i + 1 << ": \n";
		cout << "Card Value: " << Card.CardValue << endl;
		cout << "Card Name: " << Card.CardName << endl;
		cout << "Card Type: " << CardType << endl << endl;
	}
}

FGame::~FGame()
{
}