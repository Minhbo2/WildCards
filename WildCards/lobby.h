#pragma once

#include "pch.h"
#include "player.h"

using namespace std;


class FLobby
{

public:

	FLobby();
	~FLobby();

	FList<FPlayer> GetLobby() const { return Lobby; }

	void CreateLobby(int);

private:

	FList<FPlayer> Lobby;
};