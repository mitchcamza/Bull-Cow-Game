#pragma once
#include <string>


class FBullCowGame
{
public:
	FBullCowGame();	// default constructor
	int GetMaxTries() const;	
	int GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset();	// TODO: make a more rich return value
	bool CheckGuessValidity(std::string); // TODO: make a more rich return value

private:
	int MyCurrentTry;
	int MyMaxTries;
};