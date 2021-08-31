#include "FBullCowGame.h"


int FBullCowGame::GetMaxTries() { return MyMaxTries; }
int FBullCowGame::GetCurrentTry() { return MyCurrentTry; }
bool FBullCowGame::IsGameWon() { return false; }
bool FBullCowGame::CheckGuessValidity(std::string) { return false; }

void FBullCowGame::Reset()
{
	return;
}
