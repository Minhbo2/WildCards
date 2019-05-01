#include "pch.h"
#include <iostream>
#include <string>
#include "game.h"

using namespace std;


FGame::FGame()
{
	MyDeck = FDeck();
}

void FGame::NewRound()
{
	MyDeck.Reset();
}

void FGame::DealCards(FPlayer & CurrentPlayer)
{
	const int MAX_CARD_DEAL = 5;
	int CardsInHand = CurrentPlayer.GetNumCardsHold();
	for (int i = 0; i < MAX_CARD_DEAL; i++)
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
	if (WantToExchange())
	{
		cout << "How many cards do you want to exchange? \n";
		string InAnswer;
		getline(cin, InAnswer);
		int NumCard = stoi(InAnswer);
		
		if (NumCard < 5)
		{
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
		else
			CurrentPlayer.DiscardHand();

		DealCards(CurrentPlayer);
	}
}

void FGame::Score()
{
	//TODO: refactoring score system
	/*
	game will have a global var highest score
	score will get total score from each player
	the next highest will be set as the highest score player
	this way game will not have to deal with lobby at all
	*/
	int HighestScore = 0;
	FPlayer * HighestScorePlayer = nullptr; //unable to declare type ref since it is unable to init;
	for (auto It = Lobby.begin(); It != Lobby.end(); It++)
	{
		FPlayer & CurrentPlayer = *It;
		if (CurrentPlayer.TotalScore() > HighestScore)
		{
			HighestScore = CurrentPlayer.TotalScore();
			HighestScorePlayer = &CurrentPlayer;
		}
	}

	//TODO check if a player has 10 rounds won
	HighestScorePlayer->AddToRoundWon();
	PrintRoundSummary(*HighestScorePlayer);
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

	cout << CurrentPlayer.GetName() << " cards: \n\n";


	TMap<int, FCard> Hand = CurrentPlayer.GetCardsInHand();
	for (auto It = Hand.begin(); It != Hand.end(); It++)
	{
		if (CurrentPlayer.HaveCardAt(It->first))
		{
			FCard Card = It->second;
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

			cout << "Card #" << It->first + 1 << ": \n";
			cout << "Card Value: " << Card.CardValue << endl;
			cout << "Card Name: " << Card.CardName << endl;
			cout << "Card Type: " << CardType << endl << endl;
		}
	}
}

void FGame::PrintRoundSummary(FPlayer CurrentPlayer)
{
	cout << CurrentPlayer.GetName() << " won! \n";
}

void FGame::AddToLobby(FPlayer PlayerToAdd)
{
	Lobby.push_back(PlayerToAdd);
}

void FGame::DealToAll()
{
	if (Lobby.size() > 1)
	{
		for (auto It = Lobby.begin(); It != Lobby.end(); It++)
		{
			FPlayer & CurrentPlayer = *It;
			DealCards(CurrentPlayer);
		}
	}
}

FGame::~FGame()
{
}