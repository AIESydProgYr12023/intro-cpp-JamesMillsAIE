#include <iostream>
#include <Windows.h>
#include <random>
#include <time.h>

const char* ESC = "\x1b";
const char* CSI = "\x1b[";

const char* TITLE = "\x1b[5;20H";
const char* INDENT = "\x1b[5C";

const char* RESET_COLOR = "\x1b[0m";
const char* RED = "\x1b[91m";
const char* GREEN = "\x1b[92m";
const char* YELLOW = "\x1b[93m";
const char* BLUE = "\x1b[94m";
const char* MAGENTA = "\x1b[95m";
const char* WHITE = "\x1b[97m";

const int EMPTY = 0;
const int ENEMY = 1;
const int TREASURE = 2;
const int FOOD = 3;
const int ENTRANCE = 4;
const int EXIT = 5;
const int MAX_RANDOM_TYPE = FOOD + 1;

const int MAZE_WIDTH = 10;
const int MAZE_HEIGHT = 6;

const int INDENT_X = 5;
const int ROOM_DESC_Y = 8;
const int MOVEMENT_DESC_Y = 9;
const int MAP_Y = 13;

const char* EXTRA_OUTPUT_POS = "\x1b[25;6H";

const int PLAYER_INPUT_X = 30;
const int PLAYER_INPUT_Y = 23;

const int WEST = 4;
const int EAST = 6;
const int NORTH = 8;
const int SOUTH = 2;

const int LOOK = 9;
const int FIGHT = 10;

bool EnableVirtualTerminal()
{
	// Set output mode to handle virtual terminal sequences
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hOut == INVALID_HANDLE_VALUE)
	{
		return false;
	}

	DWORD dwMode = 0;
	if (!GetConsoleMode(hOut, &dwMode))
	{
		return false;
	}

	dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	
	return SetConsoleMode(hOut, dwMode);
}

void Initialize(int _map[MAZE_HEIGHT][MAZE_WIDTH])
{
	srand(time(nullptr));

	for (int y = 0; y < MAZE_HEIGHT; y++)
	{
		for (int x = 0; x < MAZE_WIDTH; x++)
		{
			int type = rand() % (MAX_RANDOM_TYPE * 2);

			if (type < MAX_RANDOM_TYPE)
				_map[y][x] = type;
			else
				_map[y][x] = EMPTY;
		}
	}

	_map[0][0] = ENTRANCE;
	_map[MAZE_HEIGHT - 1][MAZE_WIDTH - 1] = EXIT;
}

void DrawWelcomeMessage()
{
	std::cout << TITLE << MAGENTA << "Welcome to ZORP!" << RESET_COLOR << std::endl;
	std::cout << INDENT << "ZORP is a game of adventure, danger, and low cunning!" << std::endl;
	std::cout << INDENT << "It is definitely not related to any other text-based adventure game..."
		<< std::endl << std::endl;
}

void DrawRoom(int _map[MAZE_HEIGHT][MAZE_WIDTH], int _x, int _y)
{
	// Find the console output position
	int outX = INDENT_X + (6 * _x) + 1;
	int outY = MAP_Y + _y;

	// Jump to the correct location
	std::cout << CSI << outY << ";" << outX << "H";

	// Draw the room
	switch (_map[_y][_x])
	{
	case EMPTY:
		std::cout << "[ " << GREEN << "\xb0" << RESET_COLOR << " ] ";
		break;
	case ENEMY:
		std::cout << "[ " << RED << "\x94" << RESET_COLOR << " ] ";
		break;
	case TREASURE:
		std::cout << "[ " << YELLOW << "$" << RESET_COLOR << " ] ";
		break;
	case FOOD:
		std::cout << "[ " << WHITE << "\xcf" << RESET_COLOR << " ] ";
		break;
	case ENTRANCE:
		std::cout << "[ " << WHITE << "\x9d" << RESET_COLOR << " ] ";
		break;
	case EXIT:
		std::cout << "[ " << WHITE << "\xFE" << RESET_COLOR << " ] ";
		break;
	}
}

void DrawMap(int _map[MAZE_HEIGHT][MAZE_WIDTH])
{
	// Reset draw colors
	std::cout << RESET_COLOR;

	// Iterate over every room
	for (int y = 0; y < MAZE_HEIGHT; y++)
	{
		std::cout << INDENT;

		for (int x = 0; x < MAZE_WIDTH; x++)
		{
			DrawRoom(_map, x, y);
		}

		std::cout << std::endl;
	}
}

void DrawRoomDescription(int _roomType)
{
	// Reset the draw colors
	std::cout << RESET_COLOR;
	// Jump cursor to correct location
	std::cout << CSI << ROOM_DESC_Y << ";" << 0 << "H";
	// Delete 4 lines and insert 4 empty lines
	std::cout << CSI << "4M" << CSI << "4L" << std::endl;

	// Write out the description of the room
	switch (_roomType)
	{
	case EMPTY:
		std::cout << INDENT << "You are in an empty meadow. There is nothing of note here." <<
			std::endl;
		break;
	case ENEMY:
		std::cout << INDENT << "BEWARE. An enemy is approaching." <<
			std::endl;
		break;
	case TREASURE:
		std::cout << INDENT << "Your journey has been rewarded. You found some treasure." <<
			std::endl;
		break;
	case FOOD:
		std::cout << INDENT << "At last! You collect some food to sustain you on your journey." <<
			std::endl;
		break;
	case ENTRANCE:
		std::cout << INDENT << "The entrance you used to enter this maze is blocked. There is no" <<
			" going back." << std::endl;
		break;
	case EXIT:
		std::cout << INDENT << "Despite all odds, you made it to the exit. Congratulations" <<
			std::endl;
		break;
	}
}

void DrawPlayer(int _x, int _y)
{
	_x = INDENT_X + (6 * _x) + 3;
	_y = MAP_Y + _y;

	// Draw the player's position on the map
	// move the cursor to map pos and delete character at current position
	std::cout << CSI << _y << ";" << _x << "H";
	std::cout << MAGENTA << "\x81" << RESET_COLOR;
}

void DrawValidDirections(int _x, int _y)
{
	// reset draw colors
	std::cout << RESET_COLOR;
	// jump to correct location
	std::cout << CSI << MOVEMENT_DESC_Y + 1 << ";" << 0 << "H";

	// Print valid directions
	std::cout << INDENT << "You can see paths leading to the " <<
		((_x > 0) ? "west, " : "") <<
		((_x < MAZE_WIDTH - 1) ? "east, " : "") <<
		((_y > 0) ? "north, " : "") <<
		((_y < MAZE_HEIGHT - 1) ? "south, " : "") << std::endl;
}

int GetCommand()
{
	char input[50] = "\0";

	// Jump to correct location and print prompt
	std::cout << CSI << PLAYER_INPUT_Y << ";" << 0 << "H";
	std::cout << CSI << "4M";

	std::cout << INDENT << "Where to now?";
	// move the cursor to the position for player input
	std::cout << CSI << PLAYER_INPUT_Y << ";" << PLAYER_INPUT_X << "H" << YELLOW;

	// clear the input buffer, ready for player input
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());

	// Get the input and reset the colour
	std::cin >> input;
	std::cout << RESET_COLOR;

	bool shouldMove = false;
	while (input)
	{
		if (strcmp(input, "move") == 0)
		{
			shouldMove = true;
		}
		else if (shouldMove)
		{
			if (strcmp(input, "north") == 0)
				return NORTH;
			if (strcmp(input, "east") == 0)
				return EAST;
			if (strcmp(input, "south") == 0)
				return SOUTH;
			if (strcmp(input, "west") == 0)
				return WEST;
		}

		if (strcmp(input, "look") == 0)
			return LOOK;

		if (strcmp(input, "fight") == 0)
			return FIGHT;

		char next = std::cin.peek();
		if (next == '\n' || next == EOF)
			break;

		std::cin >> input;
	}

	return 0;
}

int main()
{
	// Create a 2D array
	int rooms[MAZE_HEIGHT][MAZE_WIDTH];

	bool gameOver = false;
	int playerX = 0;
	int playerY = 0;

	if (!EnableVirtualTerminal())
	{
		std::cout << "The virtual terminal processing mode could not be activated." << std::endl;
		std::cout << "Press 'Enter' to exit." << std::endl;
		std::cin.get();
		return -1;
	}

	Initialize(rooms);
	DrawWelcomeMessage();

	// Output Map
	DrawMap(rooms);

	while (!gameOver)
	{
		DrawRoomDescription(rooms[playerY][playerX]);
		DrawPlayer(playerX, playerY);

		if (rooms[playerY][playerX] == EXIT)
		{
			gameOver = true;
			continue;
		}

		// List the directions the player can take
		DrawValidDirections(playerX, playerY);
		int command = GetCommand();

		// before updating the players position, redraw the old room character
		// over the old position
		DrawRoom(rooms, playerX, playerY);

		switch (command)
		{
		case EAST:
			if (playerX < MAZE_WIDTH - 1)
				playerX++;
			break;
		case WEST:
			if (playerX > 0)
				playerX--;
			break;
		case SOUTH:
			if (playerY < MAZE_HEIGHT - 1)
				playerY++;
			break;
		case NORTH:
			if (playerY > 0)
				playerY--;
			break;
		case LOOK:
			DrawPlayer(playerX, playerY);
			std::cout << EXTRA_OUTPUT_POS << RESET_COLOR << "You look around, but see nothing worth mentioning."
				<< std::endl;
			std::cin.clear();
			std::cin.ignore(std::cin.rdbuf()->in_avail());
			std::cin.get();
			break;
		case FIGHT:
			DrawPlayer(playerX, playerY);
			std::cout << EXTRA_OUTPUT_POS << RESET_COLOR << "You could try to fight, but you don't have a weapon."
				<< std::endl;
			std::cin.clear();
			std::cin.ignore(std::cin.rdbuf()->in_avail());
			std::cin.get();
			break;
		default:
			DrawPlayer(playerX, playerY);
			std::cout << EXTRA_OUTPUT_POS << RESET_COLOR << "You try. You don't." << std::endl;
			std::cin.clear();
			std::cin.ignore(std::cin.rdbuf()->in_avail());
			std::cin.get();
			break;
		}
	}

	std::cout << std::endl << INDENT << "Press 'Enter' to exit the program." << std::endl;
	std::cin.get();

	return 0;
}