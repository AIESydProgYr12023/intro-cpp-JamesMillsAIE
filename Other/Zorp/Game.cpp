#include "Game.h"
#include <iostream>
#include <windows.h>
#include <random>
#include <time.h>


Game::Game() : m_gameOver(false)
{
	
}

Game::~Game()
{
}

bool Game::Startup()
{
	if (!EnableVirtualTerminal()) 
	{
		std::cout << "The virtual terminal processing mode could not be activated." << std::endl;
		std::cout << "Press 'Enter' to exit." << std::endl;
		std::cin.get();
		return false;
	}

	InitializeMap();

	m_player.SetPosition(Point2D{ 0,0 });

	DrawWelcomeMessage();

	return true;
}

void Game::Update()
{
	Point2D playerPos = m_player.GetPosition();
	
	if (m_map[playerPos.y][playerPos.x].GetType() == EXIT) 
	{
		m_gameOver = true;
		return;
	}
	
	int command = GetCommand();

	if (m_player.ExecuteCommand(command, m_map[playerPos.y][playerPos.x].GetType()))
		return;
		
	m_map[playerPos.y][playerPos.x].ExecuteCommand(command);
}

void Game::Draw()
{
	Point2D playerPos = m_player.GetPosition();

	// draw the description of the current room
	m_map[playerPos.y][playerPos.x].DrawDescription();
	
	// list the directions the player can take
	DrawValidDirections();
	
	// redraw the map
	DrawMap();
	// draw the player on the map
	m_player.Draw();
}

bool Game::IsGameOver()
{
	return m_gameOver;
}

bool Game::EnableVirtualTerminal()
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

void Game::InitializeMap()
{
	srand(time(nullptr));

	// fill the arrays with random room types
	for (int y = 0; y < MAZE_HEIGHT; y++)
	{
		for (int x = 0; x < MAZE_WIDTH; x++) 
		{
			int type = rand() % (MAX_RANDOM_TYPE * 2);

			if (type < MAX_RANDOM_TYPE)
			{
				if (type == TREASURE)
					type = rand() % 3 + TREASURE_HP;

				m_map[y][x].SetType(type);
			}
			else
				m_map[y][x].SetType(EMPTY);

			m_map[y][x].SetPosition(Point2D{ x, y });
		}
	}

	// set the entrance and exit of the maze
	m_map[0][0].SetType(ENTRANCE);
	m_map[MAZE_HEIGHT - 1][MAZE_WIDTH - 1].SetType(EXIT);
}

void Game::DrawWelcomeMessage()
{
	std::cout << TITLE << MAGENTA << "Welcome to ZORP!" << RESET_COLOR << std::endl;
	std::cout << INDENT << "ZORP is a game of adventure, danger, and low cunning." << std::endl;
	std::cout << INDENT << "It is definitely not related to any other text-based adventure game." << std::endl << std::endl;
}

void Game::DrawMap()
{
	Point2D position = { 0, 0 };

	// reset draw colors
	std::cout << RESET_COLOR;
	for (position.y = 0; position.y < MAZE_HEIGHT; position.y++)
	{
		for (position.x = 0; position.x < MAZE_WIDTH; position.x++) 
		{
			m_map[position.y][position.x].Draw();
		}
		std::cout << std::endl;
	}
}

void Game::DrawValidDirections()
{
	Point2D position = m_player.GetPosition();

	// reset draw colors
	std::cout << RESET_COLOR;
	// jump to the correct location
	std::cout << CSI << MOVEMENT_DESC_Y + 1 << ";" << 0 << "H";
	std::cout << INDENT << "You can see paths leading to the " <<
		((position.x > 0) ? "west, " : "") <<
		((position.x < MAZE_WIDTH - 1) ? "east, " : "") <<
		((position.y > 0) ? "north, " : "") <<
		((position.y < MAZE_HEIGHT - 1) ? "south, " : "") << std::endl;
}

int Game::GetCommand()
{
	// for now, we can't read commands longer than 50 characters
	char input[50] = "\0";

	// jump to the correct location
	std::cout << CSI << PLAYER_INPUT_Y << ";" << 0 << "H";

	// clear any existing text
	std::cout << CSI << "4M";
	// insert 4 blank lines to ensure the inventory output remains correct
	std::cout << CSI << "4L";

	std::cout << INDENT << "Enter a command.";

	// move cursor to position for player to enter input
	std::cout << CSI << PLAYER_INPUT_Y << ";" << PLAYER_INPUT_X << "H" << YELLOW;

	// clear the input buffer, ready for player input
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());

	std::cin >> input;
	std::cout << RESET_COLOR;

	bool bMove = false;
	bool bPickup = false;
	while (input) 
	{
		if (strcmp(input, "move") == 0) 
		{
			bMove = true;
		}
		else if (bMove == true) 
		{
			if (strcmp(input, "north") == 0)
				return NORTH;
			if (strcmp(input, "south") == 0)
				return SOUTH;
			if (strcmp(input, "east") == 0)
				return EAST;
			if (strcmp(input, "west") == 0)
				return WEST;
		}

		if (strcmp(input, "look") == 0) 
		{
			return LOOK;
		}

		if (strcmp(input, "fight") == 0) 
		{
			return FIGHT;
		}

		if (strcmp(input, "pick") == 0)
		{
			bPickup = true;
		}
		else if (bPickup)
		{
			if (strcmp(input, "up") == 0)
				return PICKUP;
		}

		char next = std::cin.peek();
		if (next == '\n' || next == EOF)
			break;

		std::cin >> input;
	}

	return 0;
}