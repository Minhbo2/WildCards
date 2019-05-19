#pragma once
#include "pch.h"
#include "player.h"
#include "lobby.h"
#include "wildcards.h"
#include "gihf.h"

enum class ERoundState
{
	Shuffle,
	Deal,
	Exchange,
	Score,
	Round_Reset
};



class FGame
{
public:
	FGame();

	void Run();

private:

	FPlayer * Leader;
	FLobby Lobby;
	FWildCards WildCards;
	FList<FPlayer> Players;
	bool bGameWon;

	void PrintIntro();
	void InitLobby();
	void StartRound();
	bool WantToPlayAgain();
};