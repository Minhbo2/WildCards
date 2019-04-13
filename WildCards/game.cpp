#include "pch.h"
#include "game.h"

FPlayer::FPlayer()
{
}

void FPlayer::AddToHand(int CardIndex, FCard CardToAdd)
{
	Hand.emplace(CardIndex, CardToAdd);
}

void FPlayer::CardToRemove(int CardIndex)
{
	if (CardIndex > NumCardsHold()) return; // returns empty card

	auto CardToRemove = Hand.find(CardIndex);
	Hand.erase(CardToRemove);
}


FPlayer::~FPlayer()
{
}




/*===========================================================
======================== GAME =============================
===========================================================*/



void FGame::ShuffleDeck()
{

}
