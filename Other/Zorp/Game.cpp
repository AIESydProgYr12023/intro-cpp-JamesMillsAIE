#include "Game.h"

#include <iostream>
#include <Windows.h>
#include <random>
#include <time.h>

Game::Game()
{
	m_gameOver = false;
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

	m_player.SetPosition({ 0, 0 });

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

	if (m_player.ExecuteCommand(command))
		return;

	m_map[playerPos.y][playerPos.x].ExecuteCommand(command);
}

void Game::Draw()
{
	Point2D playerPos = m_player.GetPosition();

	DrawValidDirections();

	m_map[playerPos.y][playerPos.x].DrawDescription();

	DrawMap();

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

	for (int y = 0; y < MAZE_HEIGHT; y++)
	{
		for (int x = 0; x < MAZE_WIDTH; x++)
		{
			int type = rand() % (MAX_RANDOM_TYPE * 2);

			if (type < MAX_RANDOM_TYPE)
				m_map[y][x].SetType(type);
			else
				m_map[y][x].SetType(EMPTY);

			m_map[y][x].SetPosition({ x, y });
		}
	}

	m_map[0][0].SetType(ENTRANCE);
	m_map[MAZE_HEIGHT - 1][MAZE_WIDTH - 1].SetType(EXIT);
}

void Game::DrawWelcomeMessage()
{
	std::cout << TITLE << MAGENTA << "Welcome to ZORP!" << RESET_COLOR << std::endl;
	std::cout << INDENT << "ZORP is a game of adventure, danger, and low cunning!" << std::endl;
	std::cout << INDENT << "It is definitely not related to any other text-based adventure game..."
		<< std::endl << std::endl;
}

void Game::DrawMap()
{
	Point2D position = { 0, 0 };

	// Reset draw colors
	std::cout << RESET_COLOR;

	// Iterate over every room
	for (position.y = 0; position.y < MAZE_HEIGHT; position.y++)
	{
		std::cout << INDENT;

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
	// jump to correct location
	std::cout << CSI << MOVEMENT_DESC_Y + 1 << ";" << 0 << "H";

	// Print valid directions
	std::cout << INDENT << "You can see paths leading to the " <<
		((position.x > 0) ? "west, " : "") <<
		((position.x < MAZE_WIDTH - 1) ? "east, " : "") <<
		((position.y > 0) ? "north, " : "") <<
		((position.y < MAZE_HEIGHT - 1) ? "south, " : "") << std::endl;
}

int Game::GetCommand()
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
