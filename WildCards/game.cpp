#include "pch.h"
#include "game.h"
#include <conio.h>

FGame::FGame()
{
	Lobby = FLobby();
	WildCards = FWildCards();

	GameState = EGameState::Init;
	RoundState = ERoundState::Reset;
}

void FGame::RunGame()
{
	switch (GameState)
	{
		case EGameState::Lobby:
			InitLobby();
			// make sure lobby is unchange unless game is over. otherwise will get bad memory alloc
			Players = Lobby.GetLobby();
			GameState = EGameState::Run;
			break;
		case EGameState::Run:
			StartRound();
			//only if there is a winner then Gamestate = summary
			break;
		case EGameState::Summary:
			break;
		default:
			PrintIntro();
			GameState = EGameState::Lobby;
			break;
	}
}

void FGame::StartRound()
{
	auto It = Players.begin();
	while (It != Players.end())
	{
		FPlayer & CurrentPlayer = *It;
		switch (RoundState)
		{
		case ERoundState::Shuffle:
			if (Leader == nullptr)
				WildCards.NewRound();

			RoundState = ERoundState::Deal;
			break;
		case ERoundState::Deal:
			WildCards.DealCards(CurrentPlayer);

			RoundState = ERoundState::Exchange;
			break;
		case ERoundState::Exchange:
			
			WildCards.Exchange(CurrentPlayer);
			if (Leader)
			{
				cout << CurrentPlayer.GetTotalScore() << endl;
				cout << Leader->GetTotalScore() << endl;
			}
			RoundState = ERoundState::Score;
			break;
		case ERoundState::Score:
			if (Leader == nullptr || Leader->GetTotalScore() < CurrentPlayer.GetTotalScore())
				Leader = &CurrentPlayer;

			RoundState = (It == --Players.end()) ? ERoundState::Reset : ERoundState::Deal;
			It++;
			break;
		default:
			//TODO: Bugs
			// Deck is not updating, previous player will always win
			if (Leader)
			{
				system("CLS");
				Leader->AddToRoundWon();
				cout << Leader->GetName() << " won this round!" << endl;
				cout <<  "Total point: " << Leader->GetRoundWon() << endl;
				//check to see if leader has won the game
				cout << "Please hit Enter to continue:";
				char Key;
				Key = _getch();
			}

			Leader     = nullptr;
			RoundState = ERoundState::Shuffle;
			break;
		}
	}
}

void FGame::PrintIntro()
{
	cout << "WELCOME TO WILD CARDS. \n\n";
	cout << "Rules:\n";
	cout << "Each round, players will receive 5 cards.\n";
	cout << "Each player will keep or exchange up to 5 cards in hand.\n";
	cout << "At the end of a round, a player with the highest score will the round.\n";
	cout << "First player to win 5 rounds wins the game.\n\n";
}

void FGame::InitLobby()
{
	cout << "Enter 2 - 4 for number of players: ";
	int NumPlayers;
	cin >> NumPlayers;

	Lobby.CreateLobby(NumPlayers);
}