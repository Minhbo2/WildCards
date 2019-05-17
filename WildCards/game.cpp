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
	bool bPlayAgain = false;
	do 
	{
		while (!bGameWon)
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

				//only if there is a winner then Gamestate = summary
				if (bGameWon)
					GameState = EGameState::Summary;
				else
					StartRound();

				break;
			case EGameState::Summary:

				bPlayAgain = AskPlayAgain();
				GameState = EGameState::Lobby;

				break;
			default:

				PrintIntro();
				bGameWon = false;
				GameState = EGameState::Lobby;

				break;
			}
		}
	} while (bPlayAgain);
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
			
			constexpr int MAX_ROUND = 5;

			if(Leader)
			{
				system("CLS");
				Leader->AddToRoundWon();
				
				if (Leader->GetRoundWon() >= MAX_ROUND)
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

bool FGame::AskPlayAgain()
{
	FString PlayAgain = "Would you like to play again?";
	char InputChar = GetUserInput<char>(PlayAgain);
	return (tolower(InputChar) == 'y');
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
	FString EnterLobby =  "Enter 2 - 4 for number of players: ";
	int NumPlayers = GetUserInput<int>(EnterLobby);
	Lobby.CreateLobby(NumPlayers);
}