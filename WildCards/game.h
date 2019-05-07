#pragma once
#include "pch.h"
#include "player.h"
#include "lobby.h"
#include "wildcards.h"


enum class EGameState
{
	Init, // print intro
	Lobby, // create lobby
	Run, // run game loop 
	Summary // print summary at the end of game and ask to play again
};

enum class ERoundState
{
	Shuffle,
	Deal,
	Exchange,
	Score,
	End_Round
};



class FGame
{
public:
	FGame();

	void RunGame();

private:

	EGameState GameState;
	ERoundState RoundState;
	FPlayer * Leader;
	FLobby Lobby;
	FWildCards WildCards;
	FList<FPlayer> Players;

	void PrintIntro();
	void InitLobby();
	void StartRound();
};