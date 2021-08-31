#include "FBullCowGame.h"


int FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
bool FBullCowGame::IsGameWon() const { return false; }
bool FBullCowGame::CheckGuessValidity(std::string) { return false; }

void FBullCowGame::Reset()
{
	return;
}
