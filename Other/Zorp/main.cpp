#include <iostream>

#include "Game.h"

int main()
{
	Game game;
	if (!game.Startup())
		return -1;

	// game loop
	while (!game.IsGameOver())
	{
		game.Draw();
		game.Update();
	} // end game loop

	// jump to the correct location
	std::cout << CSI << PLAYER_INPUT_Y << ";" << 0 << "H";
	std::cout << std::endl << INDENT << "Press 'Enter' to exit the program.";
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	std::cin.get();

	return 0;
}