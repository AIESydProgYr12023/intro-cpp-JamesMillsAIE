#include <iostream>
#include <time.h>

int main()
{
	// seed the random with the current time
	srand(time(nullptr));

	int guess = 0;

	// generate a random number to be guessed
	int randomNumber = rand() % 100;

	do
	{
		// prompt for input
		std::cout << "Enter your guess: ";
		std::cin >> guess;

		// Feedback to user (higher or lower)
		if (randomNumber < guess)
			std::cout << "Lower" << std::endl;

		if (randomNumber > guess)
			std::cout << "Higher" << std::endl;

	} 
	while (randomNumber != guess);

	std::cout << "Correct!" << std::endl;

	return 0;
}