// WildCards.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "deck.h"
#include "game.h"
#include <vector>



int main()
{

	FCard Card = FCard(10, "King", ECardType::Club);
	FCard Card2 = FCard(1, "Ace", ECardType::Heart);
	FCard Card3 = FCard(5, "5", ECardType::Space);
	FPlayer Player_1 = FPlayer();
	Player_1.AddToHand(Card);
	Player_1.AddToHand(Card2);
	Player_1.AddToHand(Card3);

	short CardInHand = Player_1.NumCardsHold();
	std::cout << CardInHand << std::endl;




	return 0;
}
