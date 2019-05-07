#include "pch.h"
#include "wildcards.h"


FWildCards::FWildCards()
{
	MyDeck = FDeck();
}

void FWildCards::NewRound()
{
	MyDeck.Reset();
}

void FWildCards::Exchange(FPlayer & CurrentPlayer)
{
	if (WantToExchange())
	{
		cout << "How many cards do you want to exchange? \n";
		FString InAnswer;
		cin >> InAnswer;
		int NumCard = stoi(InAnswer);

		if (NumCard < 5)
		{
			for (int i = 0; i < NumCard; i++)
			{
				//TODO: might b helpful to write template function to handle input from player
				cout << "Select a card#: ";
				FString InIndex;
				cin >> InIndex;
				int CardIndex = stoi(InIndex);
				CurrentPlayer.CardToRemove(CardIndex - 1);
			}
		}
		else
			CurrentPlayer.DiscardHand();

		DealCards(CurrentPlayer);
	}
}

bool FWildCards::HasHigherScore(FPlayer CurrentPlayer)
{
	return false;
}

void FWildCards::DealCards(FPlayer & CurrentPlayer)
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

bool FWildCards::WantToExchange()
{
	cout << "Do you want to exchange cards? ";
	cout << "Y/y or N/n \n\n";

	string InAnswer;
	// if use getline() will make console skips first answer
	cin >> InAnswer;
	cout << endl;

	char Answer = tolower(InAnswer[0]);
	if (Answer == 'y')
		return true;

	return false;
}

void FWildCards::PrintPlayerHand(FPlayer CurrentPlayer)
{
	system("CLS");

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

void FWildCards::PrintRoundSummary(FPlayer CurrentPlayer)
{
	cout << CurrentPlayer.GetName() << " won this round! \n";
	cout << "Total Score: " << CurrentPlayer.GetRoundWon() << endl;
}

FWildCards::~FWildCards()
{
}