/* This is the console executable that makes use of the BullCow class.
This acts as the view in a MVC pattern, and is responsible for all
user interaction. For game logic see the FBullCowGame class.
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;


// Function Prototypes
void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();

FBullCowGame BCGame;	// Instantiate a new game


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


// introduce the game
void PrintIntro()
{
	std::cout << "Welcome to Bulls and Cows - a fun word game\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();	

	// loop for the number of turns asking for guesses
	// TODO: change from FOR to WHILE loop once we are validating tries
	for (int32 count = 0; count < MaxTries; count++)
	{
		FText Guess = GetValidGuess();	// TODO: check for valid guesses



		// submit valid guess to the game and receive counts
		FBullCowCount FBullCowCount = BCGame.SubmitGuess(Guess);

		std::cout << "Bulls = " << FBullCowCount.Bulls;
		std::cout << ". Cows = " << FBullCowCount.Cows << "\n\n";

		// provide a method for counting bulls & cows & increment current try
	}
	// TODO: add a game summary
}

// loop continually until the user enters a valid guess
FText GetValidGuess()
{
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do
	{
		// get a guess from the player
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << ". Enter your guess: ";
		FText Guess = "";	
		std::getline(std::cin, Guess);	

		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
			break;
	
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word without any repeating letters.\n";
			break;

		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter all lowercase letters.\n";
			break;

		default:
			return Guess;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK);	// keep looping until we get no errors
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n): ";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}

