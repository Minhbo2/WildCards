#include "pch.h"
#include "game.h"
#include <conio.h>

FGame::FGame()
{
	Lobby      = FLobby();
	WildCards  = FWildCards();
}

void FGame::Run()
{
	bool bPlayAgain;
	do 
	{
		//reset/intro
		bGameWon   = false;
		bPlayAgain = false;
		PrintIntro();

		// setup game lobby
		InitLobby();
		Players = Lobby.GetLobby();	

		// start game
		while (!bGameWon)
			StartRound();

		// continue or nah
		bPlayAgain = WantToPlayAgain();
	}
	while (bPlayAgain);
}

void FGame::StartRound()
{
	ERoundState RoundState = ERoundState::Round_Reset;
	auto It = Players.begin();
	while (It != Players.end())
	{
		FPlayer & CurrentPlayer = *It;
		switch (RoundState)
		{
		case ERoundState::Shuffle:
			
			WildCards.NewDeck();
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

			if (Leader == nullptr ||
				Leader->GetTotalScore() < CurrentPlayer.GetTotalScore())
				Leader = &CurrentPlayer;
			else if (Leader->GetTotalScore() == CurrentPlayer.GetTotalScore())
			{
				cout << "Uh-oh, looks like we have a tie.\n";
				cout << "Dealing a new hand.\n";
				RoundState = ERoundState::Deal;
				break;
			}
			
			RoundState = (It == --Players.end()) ? ERoundState::Round_Reset : ERoundState::Deal;

			if (RoundState == ERoundState::Round_Reset)
			{
				system("CLS");
				constexpr int MAX_ROUND = 3;
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
					cout << "Cards point: " << Leader->GetTotalScore() << endl;
				}

				cout << "Please press any key to continue:";
				char Key;
				Key = _getch();
			}
			
			It++;

			break;
		default:

			Leader = nullptr;
			RoundState = ERoundState::Shuffle;

			break;
		}
	}
}

bool FGame::WantToPlayAgain()
{
	system("CLS");
	FString PlayAgain = "Would you like to play again?";
	char InputChar = GetUserInput<char>(PlayAgain);
	return (tolower(InputChar) == 'y');
}

void FGame::PrintIntro()
{
	system("CLS");
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