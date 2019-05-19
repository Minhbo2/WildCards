#include "pch.h"
#include "lobby.h"
#include "gihf.h"


FLobby::FLobby()
{
}

void FLobby::CreateLobby(int NumPlayers)
{
	Lobby.clear();
	for (int i = 0; i < NumPlayers; i++)
	{	
		cout << "Player " << i << endl;
		FString AskForName = " Enter Desire Name: ";
		FString DesiredName = GetUserInput<FString>(AskForName);
		FPlayer PlayerToAdd = FPlayer(DesiredName);
		Lobby.push_back(PlayerToAdd);
	}
}

FLobby::~FLobby()
{
}