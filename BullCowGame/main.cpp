/* This is the console executable that makes use of the BullCow class.
This acts as the view in a MVC pattern, and is responsible for all
user interaction. For game logic see the FBullCowGame class.
*/

#pragma once

#include <iostream>
#include <string>
#include "FBullCowGame.h"

// to make syntax Unreal friendly
using FText = std::string;
using int32 = int;

// Function Prototypes
void PrintIntro();
void PlayGame();
void PrintGameSummary();
FText GetValidGuess();
bool AskToPlayAgain();

FBullCowGame BCGame;	// Instantiate a new game

// entry-point for the application
int main()
{
	bool bPlayAgain = false;
	do
	{
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);	

	return 0;
}


void PrintIntro()
{
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << std::endl;
	std::cout << "          }   {         ___ " << std::endl;
	std::cout << "          (o o)        (o o) " << std::endl;
	std::cout << "   /-------\\ /          \\ /-------\\ " << std::endl;
	std::cout << "  / | BULL |O            O| COW  | \\ " << std::endl;
	std::cout << " *  |-,--- |              |------|  * " << std::endl;
	std::cout << "    ^      ^              ^      ^ " << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}

// plays a single game to completion
void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();	

	// loop asking for guesses while the game 
	// is NOT won and there are still tries remaining
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
	{
		FText Guess = GetValidGuess();

		// submit valid guess to the game and receive counts
		FBullCowCount FBullCowCount = BCGame.SubmitValidGuess(Guess);

		std::cout << "Bulls = " << FBullCowCount.Bulls;
		std::cout << ". Cows = " << FBullCowCount.Cows << "\n\n";
	}
	PrintGameSummary();
	return;
}

// loop continually until the user enters a valid guess
FText GetValidGuess()
{
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do
	{
		// get a guess from the player
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << " of " << BCGame.GetMaxTries();
		std::cout << ". Enter your guess: ";
		std::getline(std::cin, Guess);	

		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n\n";
			break;
	
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word without any repeating letters.\n\n";
			break;

		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter all lowercase letters.\n\n";
			break;

		default:
			// assume the guess is valid
			break;
		}
	} while (Status != EGuessStatus::OK);	// keep looping until we get no errors
	
	return Guess;
}

void PrintGameSummary()
{
	if (BCGame.IsGameWon())
	{
		std::cout << "WELL DONE - YOU WIN!\n";
	}
	else
	{
		std::cout << "Better luck next time!\n";
	}
	return;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again with the same hidden word? (y/n): ";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}

