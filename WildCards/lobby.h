#pragma once

#include "pch.h"
#include "player.h"


class FLobby
{

public:

	FLobby();
	~FLobby();

	FList<FPlayer> GetLobby() const { return Lobby; }

	void AddToLobby(FPlayer);

private:

	FList<FPlayer> Lobby;
};