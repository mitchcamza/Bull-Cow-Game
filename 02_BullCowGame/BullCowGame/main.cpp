#include <iostream>
using namespace std;

int main()
{
	constexpr int WORD_LENGTH = 5;
	cout << "Welcome to Bulls and Cows - a fun word game\n";
	cout << "Can you guess the " << WORD_LENGTH;
	cout << " letter isogram I'm thinking of?\n";

	return 0;
}