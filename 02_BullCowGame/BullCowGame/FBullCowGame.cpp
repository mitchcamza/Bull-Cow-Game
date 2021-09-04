#pragma once
#include "FBullCowGame.h"
#include <map>

// To make syntax Unreal friendly
#define TMap std::map 

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

bool FBullCowGame::IsIsogram(FString Word) const
{
	// treat 0 and 1 letter words as isograms
	if (Word.length() <= 1) { return true; }

	TMap<char, bool> LetterSeen;	// set up our map

	// loop through all the letters of the guess
	for (auto Letter : Word)		// for all letters in the word
	{
		Letter = tolower(Letter);	// convert each letter to lowercase
		if (LetterSeen[Letter])		// if the letter is in the map
		{
			return false;	// the guess is NOT an isogram
		}
		else
		{
			LetterSeen[Letter] = true;	// add the letter to the map as seen
		}
	}
	
	return true;	// for example in cases where '\0' is entered
}

bool FBullCowGame::IsLowercase(FString Word) const
{
	for (auto Letter : Word)
	{
		if (!islower(Letter))	// if not a lowercase letter
		{
			return false;
		}
	}
	return true;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const 
{ 
	if (!IsIsogram(Guess))	// if the guess isn't an isogram
	{
		return EGuessStatus::Not_Isogram;	
	}
	else if (!IsLowercase(Guess))	// if the guess isn't lowercase
	{
		return EGuessStatus::Not_Lowercase;	
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

int32 FBullCowGame::GetMaxTries() const 
{ 
	TMap<int32, int32> WordLengthToMaxTries { {3,4}, {4,7}, {5,10}, {6,15}, {7,20} };
	return WordLengthToMaxTries[MyHiddenWord.length()];
}

void FBullCowGame::Reset()
{
	const FString HIDDEN_WORD = "planet";	// this must be an isogram
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
