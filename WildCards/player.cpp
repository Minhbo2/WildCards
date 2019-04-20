#include "pch.h"
#include "player.h"


FPlayer::FPlayer()
{
}

void FPlayer::AddToHand(int CardIndex, FCard CardToAdd)
{
	Hand.emplace(CardIndex, CardToAdd);
}

void FPlayer::CardToRemove(int CardIndex)
{
	if (CardIndex > GetNumCardsHold()) return;

	auto CardToRemove = Hand.find(CardIndex);
	Hand.erase(CardToRemove);
}

bool FPlayer::HaveCardAt(int CardIndex)
{
	auto It = Hand.find(CardIndex);
	if (It != Hand.end())
		return true;

	return false;
}

FPlayer::~FPlayer()
{
}