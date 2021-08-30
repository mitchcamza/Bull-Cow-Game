#include <iostream>
#include <string>
using namespace std;

int main()
{
	// introduce the game
	constexpr int WORD_LENGTH = 5;
	cout << "Welcome to Bulls and Cows - a fun word game\n";
	cout << "Can you guess the " << WORD_LENGTH;
	cout << " letter isogram I'm thinking of?\n";
	cout << endl;

	// get a guess from the player
	cout << "Enter your guess: ";
	string Guess = "";
	cin >> Guess;

	// repeat the guess back to them
	cout << "Your guess was: " << Guess << endl;

	// two word guesses cause an error
	// cin strips trailing whitespace and the second word is left in the input stream
	cout << "Enter your guess: ";
	cin >> Guess;
	cout << "Your guess was: " << Guess << endl;

	return 0;
}