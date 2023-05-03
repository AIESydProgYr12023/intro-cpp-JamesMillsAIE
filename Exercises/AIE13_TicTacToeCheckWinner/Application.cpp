#include "Application.h"

#include <iostream>

Application::Application() = default;

Application::~Application() = default;

void Application::Run()
{
	std::cout << "Expected: 1 - Actual: " << CheckWinner(m_board0, 'x') << std::endl;
	std::cout << "Expected: 0 - Actual: " << CheckWinner(m_board0, 'o') << std::endl;
	std::cout << "Expected: 0 - Actual: " << CheckWinner(m_board1, 'x') << std::endl;
	std::cout << "Expected: 1 - Actual: " << CheckWinner(m_board1, 'o') << std::endl;
	std::cout << "Expected: 1 - Actual: " << CheckWinner(m_board2, 'x') << std::endl;
	std::cout << "Expected: 0 - Actual: " << CheckWinner(m_board2, 'o') << std::endl;
	std::cout << "Expected: 0 - Actual: " << CheckWinner(m_board3, 'x') << std::endl;
	std::cout << "Expected: 1 - Actual: " << CheckWinner(m_board3, 'o') << std::endl;
	std::cout << "Expected: 0 - Actual: " << CheckWinner(m_board4, 'x') << std::endl;
	std::cout << "Expected: 0 - Actual: " << CheckWinner(m_board4, 'o') << std::endl;
}

bool Application::CheckWinner(char _board[BOARD_DIMENSIONS][BOARD_DIMENSIONS], char _token)
{
	// count the number of tokens in each row
	for (int rowId = 0; rowId < 3; rowId++)
	{
		int count = 0;
		for (int colId = 0; colId < 3; colId++)
			if (_board[rowId][colId] == _token)
				count += 1;

		// there are 3 in a row, return true indicating a win
		if (count == 3) return true;
	}

	// count the number of tokens in each column
	for (int colId = 0; colId < 3; colId++)
	{
		int count = 0;
		for (int rowId = 0; rowId < 3; rowId++)
			if (_board[rowId][colId] == _token)
				count += 1;

		// there are 3 in a row, return true indicating a win
		if (count == 3) return true;
	}

	// check the number of tokens diagionally (topright to bottom left)
	int count = 0;
	for (int id = 0; id < 3; id++)
	{
		if (_board[id][2 - id] == _token)
			count++;

		// there are 3 in a row, return true indicating a win
		if (count == 3) return true;
	}

	// check the number of tokens diagionally (topright to bottom left)
	count = 0;
	for (int id = 0; id < 3; id++)
	{
		if (_board[id][id] == _token)
			count++;

		// there are 3 in a row, return true indicating a win
		if (count == 3) return true;
	}

	// if we get here, than we have not found a win condition for the given token
	// then return false indicating no win
	return false;
}