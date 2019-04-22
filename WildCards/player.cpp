#include "pch.h"
#include "player.h"


FPlayer::FPlayer()
{
}

FPlayer::FPlayer(FString Name)
{
	this->PlayerName = Name;
}

void FPlayer::AddToHand(int CardIndex, FCard CardToAdd)
{
	Hand.emplace(CardIndex, CardToAdd);
}

void FPlayer::CardToRemove(int CardIndex)
{
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

int FPlayer::TotalScore()
{
	int TotalScoreInHand = 0;
	for (auto It : Hand)
	{
		FCard Card = It.second;
		TotalScoreInHand = TotalScoreInHand + Card.CardValue;
	}

	return TotalScoreInHand;
}

FPlayer::~FPlayer()
{
}