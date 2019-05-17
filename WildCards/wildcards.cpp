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
		FString AskCardAmount = "How many cards do you want to exchange?";
		int NumCard = GetUserInput<int>(AskCardAmount);
		if (NumCard < 5)
		{
			for (int i = 0; i < NumCard; i++)
			{
				FString AskToSelect = "Select a card#: ";
				int CardIndex = GetUserInput<int>(AskToSelect);
				CurrentPlayer.CardToRemove(CardIndex - 1);
			}
		}
		else
			CurrentPlayer.DiscardHand();

		DealCards(CurrentPlayer);
	}
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
	FString AskToExchange = "Do you want to exchange cards? Y/y or N/n: ";
	char Answer = GetUserInput<char>(AskToExchange);
	return (tolower(Answer) == 'y') ? true : false;
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

FWildCards::~FWildCards()
{
}