#include "pch.h"
#include "deck.h"
#include <iostream>
#include <algorithm>





//============================================================
// ********************CARD STRUCT*****************************
//============================================================

FCard::FCard()
{
	this->CardValue = 0;
	this->CardName = "Null";
}



FCard::FCard(int CardValue, FString CardName, ECardType CardType)
{
	this->CardValue = CardValue;
	this->CardName = CardName;
	this->CardType = CardType;
}



FCard::~FCard()
{
}






//============================================================
// ********************DECK CLASS*****************************
//============================================================
// Constructor
FDeck::FDeck()
{
	CreateDeck();
	Reset();
}




void FDeck::Reset()
{
	MyDeck.clear();
	MyDeck = MainDeck;
	ShuffleDeck();
}






// Create a standard deck of card 
void FDeck::CreateDeck()
{
	/*
	each deck has 4 types of card: heart, space, club, diamond
	each type has 13 cards: 1/ace - 10. jack, queen, king
	a deck has 52 cards: 4 x 13 
	*/

	const int CARD_TYPES = 4;
	const int CARDS_PER_TYPE = 13;

	for (int i = 0; i < CARD_TYPES; i++)
	{
		ECardType CurrentCardType = ECardType(i);

		for (int j = 1; j <= CARDS_PER_TYPE; j++)
		{
			FString CardName = "";
			int CardValue = (j > 10) ? 10 : j;

			if (j == 1)
				CardName = "Ace";
			else if (j == 11)
				CardName = "Jack";
			else if (j == 12)
				CardName = "Queen";
			else if (j == 13)
				CardName = "King";
			else
				CardName = std::to_string(j);

			FCard Card = FCard(CardValue, CardName, CurrentCardType);
			MainDeck.push_back(Card);
		}
	}
}






FCard FDeck::GetTopCardFromDeck()
{
	// a little bit cheating here. but this is more efficient compare to having using .erase(vector.front()) and reallocate memory every time. 
	FCard TopCard = GetMyDeck().back();
	MyDeck.pop_back();
	return TopCard;
}






void FDeck::ShuffleDeck()
{
	std::srand(unsigned(std::time(0)));
	std::random_shuffle(MyDeck.begin(), MyDeck.end());
}





// Destructor
FDeck::~FDeck()
{

}