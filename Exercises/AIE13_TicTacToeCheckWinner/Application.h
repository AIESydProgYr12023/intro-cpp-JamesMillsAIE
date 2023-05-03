#pragma once

#define BOARD_DIMENSIONS 3

class Application
{
public:
	Application();
	~Application();

	void Run();

	bool CheckWinner(char _board[BOARD_DIMENSIONS][BOARD_DIMENSIONS], char _token);

private:
	char m_board0[BOARD_DIMENSIONS][BOARD_DIMENSIONS] =
	{
		{ 'x', ' ', ' ' },
		{ ' ', 'x', ' ' },
		{ ' ', ' ', 'x' },
	};

	char m_board1[BOARD_DIMENSIONS][BOARD_DIMENSIONS] =
	{
		{ ' ', 'o', ' ' },
		{ ' ', 'o', ' ' },
		{ ' ', 'o', ' ' },
	};

	char m_board2[BOARD_DIMENSIONS][BOARD_DIMENSIONS] =
	{
		{ ' ', 'o', ' ' },
		{ 'x', 'x', 'x' },
		{ ' ', 'o', ' ' },
	};

	char m_board3[BOARD_DIMENSIONS][BOARD_DIMENSIONS] =
	{
		{ 'x', 'o', 'o' },
		{ 'x', 'o', 'x' },
		{ 'o', 'x', 'x' },
	};

	char m_board4[BOARD_DIMENSIONS][BOARD_DIMENSIONS] =
	{
		{ 'o', 'o', 'x' },
		{ 'x', 'x', 'o' },
		{ 'o', 'x', 'x' },
	};

};