#include <iostream>
#include <string>
using namespace std;

// Function Prototypes
void PrintIntro();
string GetGuessAndPrintBack();

// Entry point for our application
int main()
{
	PrintIntro();
	GetGuessAndPrintBack();
	GetGuessAndPrintBack();
	cout << endl;

	return 0;
}

// introduce the game
void PrintIntro()
{
	constexpr int WORD_LENGTH = 5;
	cout << "Welcome to Bulls and Cows - a fun word game\n";
	cout << "Can you guess the " << WORD_LENGTH;
	cout << " letter isogram I'm thinking of?\n";
	cout << endl;
	return;
}

// get a guess from the player
// notice the side effects introduced. This function is playing two roles.
string GetGuessAndPrintBack()
{
	cout << "Enter your guess: ";
	string Guess = "";
	getline(cin, Guess);
	
	// repeat the guess back to them
	cout << "Your guess was: " << Guess << endl;
	return Guess;
}