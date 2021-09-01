#include "FBullCowGame.h"


FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
bool FBullCowGame::IsGameWon() const { return false; }
bool FBullCowGame::CheckGuessValidity(FString) { return false; }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	return;
}

// receives a VALID guess, increments turn and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	// increment the current try
	MyCurrentTry++;

	// setup a return variable
	FBullCowCount BullCowCount;

	// loop through all letters in the guess
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++) 
	{
		// compare letters against the hidden word
		for (int32 GChar = 0; GChar < HiddenWordLength; GChar++)
		{
			//if (Guess[MHWChar] == MyHiddenWord[GChar])	
			// iterates through each char in hidden word and compares it
			// with each char in guess. This still achieves the same outcome in the end,
			// but uses a confusing backwards approach.
			// it would make more sense to iterate through each char in the
			// guess and compare it with the hidden word.	
			// ie change (Guess[i] == MyHiddenWord[j]) to (Guess[j] == MyHiddenWord[i])

			if (Guess[GChar] == MyHiddenWord[MHWChar])	// if they match then
			{
				if (MHWChar == GChar)	// if they're in the same place
				{
					BullCowCount.Bulls++;	// increment bulls 
				}
				else
				{
					BullCowCount.Cows++;	// increment cows
				}
			}
		}
	}

	return BullCowCount;
}
