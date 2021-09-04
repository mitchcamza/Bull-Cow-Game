#include "FBullCowGame.h"
#include <map>
#define TMap std::map 


FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

bool FBullCowGame::IsIsogram(FString Guess) const
{
	// treat 0 and 1 letter words as isograms
	
	// loop through all the letters of the guess
		// if the letter is in the map
			// the guess is NOT an isogram
		// otherwise
			// add the letter to the map as seen
	
	return true;	// for example in cases where /0 is entered
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const 
{ 
	if (!IsIsogram(Guess))	// if the guess isn't an isogram
	{
		return EGuessStatus::Not_Isogram;	// TODO: write function
	}
	else if (false)	// if the guess isn't lowercase
	{
		return EGuessStatus::Not_Lowercase;	// TODO: write function
	}
	else if (Guess.length() != GetHiddenWordLength())	// if the guess length is wrong
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}

}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";

	MyMaxTries = MAX_TRIES;	
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	bGameIsWon = false;
	return;
}

// receives a VALID guess, increments turn and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 WordLength = MyHiddenWord.length();	// assuming the same length as guess

	// loop through all letters in the hidden word
	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++) 
	{
		// compare letters against the guess
		for (int32 GChar = 0; GChar < WordLength; GChar++)
		{
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
	if (BullCowCount.Bulls == WordLength)
	{
		bGameIsWon = true;
	}
	else
	{
		bGameIsWon = false;
	}

	return BullCowCount;
}
