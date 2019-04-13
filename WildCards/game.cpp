#include "pch.h"
#include "game.h"

FPlayer::FPlayer()
{
}

void FPlayer::AddToHand(FCard CardToAdd)
{
	Hand.emplace(CardToAdd);
}

FCard FPlayer::CardToRemove(short CardIndex)
{
	if (CardIndex > NumCardsHold()) return FCard(); // returns empty card

	return Hand.at(CardIndex);
}


FPlayer::~FPlayer()
{
}
