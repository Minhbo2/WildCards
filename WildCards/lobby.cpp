#include "pch.h"
#include "lobby.h"



FLobby::FLobby()
{
}

void FLobby::CreateLobby(int NumPlayers)
{
	for (int i = 0; i < NumPlayers; i++)
	{	
		FString PlayerName = "Player ";
		PlayerName += to_string(i + 1);
		FPlayer PlayerToAdd = FPlayer(PlayerName);
		Lobby.push_back(PlayerToAdd);
	}
}

FLobby::~FLobby()
{
}