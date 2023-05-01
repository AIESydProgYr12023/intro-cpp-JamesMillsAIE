#include "Room.h"

#include "GameDefines.h"
#include <iostream>

Room::Room()
{
	m_type = EMPTY;
	m_mapPosition.x = 0;
	m_mapPosition.y = 0;
}

Room::~Room()
{
}

void Room::SetPosition(Point2D _position)
{
	m_mapPosition = _position;
}

void Room::SetType(int _type)
{
	m_type = _type;
}

int Room::GetType()
{
	return m_type;
}

void Room::Draw()
{
	// Find the console output position
	int outX = INDENT_X + (6 * m_mapPosition.x) + 1;
	int outY = MAP_Y + m_mapPosition.y;

	// Jump to the correct location
	std::cout << CSI << outY << ";" << outX << "H";

	// Draw the room
	switch (m_type)
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

void Room::DrawDescription()
{
	// Reset the draw colors
	std::cout << RESET_COLOR;
	// Jump cursor to correct location
	std::cout << CSI << ROOM_DESC_Y << ";" << 0 << "H";
	// Delete 4 lines and insert 4 empty lines
	std::cout << CSI << "4M" << CSI << "4L" << std::endl;

	// Write out the description of the room
	switch (m_type)
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

bool Room::ExecuteCommand(int _command)
{
	switch (_command)
	{
	case LOOK:
		std::cout << EXTRA_OUTPUT_POS << RESET_COLOR << "You look around, but see nothing worth mentioning."
			<< std::endl;
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cin.get();
		return true;
	case FIGHT:
		std::cout << EXTRA_OUTPUT_POS << RESET_COLOR << "You could try to fight, but you don't have a weapon."
			<< std::endl;
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cin.get();
		return true;
	default:
		std::cout << EXTRA_OUTPUT_POS << RESET_COLOR << "You try. You don't." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cin.get();
		break;
	}

	return false;
}
