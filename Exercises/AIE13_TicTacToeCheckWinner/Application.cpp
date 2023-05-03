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
	// row


	// column


	// top-right to bottom-left


	// top-left to bottom-right

	// if we get here, than we have not found a win condition for the given token
	// then return false indicating no win
	return false;
}