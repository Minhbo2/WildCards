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
			if (IsGameWon())
				GameState = EGameState::Summary;

			break;
		case EGameState::Summary:
			// print who has won the game.
			break;
		default:
			
			PrintIntro();
			bGameWon = false;
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
			
			WildCards.NewRound();
			RoundState = ERoundState::Deal;

			break;
		case ERoundState::Deal:
			
			CurrentPlayer.DiscardHand();
			WildCards.DealCards(CurrentPlayer);
			RoundState = ERoundState::Exchange;

			break;
		case ERoundState::Exchange:

			WildCards.Exchange(CurrentPlayer);
			RoundState = ERoundState::Score;

			break;
		case ERoundState::Score:
			
			if (Leader == nullptr || Leader->GetTotalScore() < CurrentPlayer.GetTotalScore())
				Leader = &CurrentPlayer;

			RoundState = (It == --Players.end()) ? ERoundState::Reset : ERoundState::Deal;
			It++;
			
			break;
		default:
			
			if(Leader)
			{
				system("CLS");
				Leader->AddToRoundWon();
				
				if (Leader->GetRoundWon() >= 5)
				{
					cout << Leader->GetName() << " won the game!" << endl;
					bGameWon = true;
				}
				else
				{
					cout << Leader->GetName() << " won this round!" << endl;
					cout << "Total point: " << Leader->GetRoundWon() << endl;
				}
				
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