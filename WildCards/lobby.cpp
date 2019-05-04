#include "pch.h"
#include "lobby.h"

FLobby::FLobby()
{
}

void FLobby::AddToLobby(FPlayer PlayerToAdd)
{
	Lobby.push_back(PlayerToAdd);
}

FLobby::~FLobby()
{
}