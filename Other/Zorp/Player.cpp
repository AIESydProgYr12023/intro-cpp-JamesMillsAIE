#include "Player.h"
#include "GameDefines.h"

#include <iostream>
#include <algorithm>

Player::Player() : m_mapPosition({ 0, 0 })
{
	
}

Player::Player(int _x, int _y) : m_mapPosition({ _x, _y })
{

}

Player::~Player()
{
}

void Player::SetPosition(Point2D _position)
{
	m_mapPosition = _position;
}

Point2D Player::GetPosition()
{
	return m_mapPosition;
}

void Player::Draw()
{
	Point2D outPos = 
	{
		INDENT_X + (6 * m_mapPosition.x) + 3,
		MAP_Y + m_mapPosition.y 
	};

	// draw the player's position on the map
	// move cursor to map pos and delete character at current position
	std::cout << CSI << outPos.y << ";" << outPos.x << "H";
	std::cout << MAGENTA << "\x81" << RESET_COLOR;

	std::cout << INVENTORY_OUTPUT_POS;
	for (auto it = m_powerups.begin(); it != m_powerups.end(); it++)
	{
		std::cout << (*it).GetName() << "\t";
	}
}

bool Player::ExecuteCommand(int _command, int _roomType)
{
	switch (_command) 
	{
	case EAST:
		if (m_mapPosition.x < MAZE_WIDTH - 1)
			m_mapPosition.x++;
		return true;
	case WEST:
		if (m_mapPosition.x > 0)
			m_mapPosition.x--;
		return true;
	case NORTH:
		if (m_mapPosition.y > 0)
			m_mapPosition.y--;
		return true;
	case SOUTH:
		if (m_mapPosition.y < MAZE_HEIGHT - 1)
			m_mapPosition.y++;
		return true;
	case PICKUP:
		return Pickup(_roomType);
	}

	return false;
}

bool Player::Pickup(int _roomType)
{
	static const char itemNames[15][30] = {
		"indifference", "invisibility", "invulnerability", "incontinence",
		"improbability", "impatience", "indecision", "inspiration",
		"independence", "incurability", "integration", "invocation",
		"inferno", "indigestion", "inoculation"
	};

	int item = rand() % 15;
	char name[30] = "";

	switch (_roomType)
	{
	case TREASURE_HP:
		strcpy_s(name, "Potion of ");
		break;

	case TREASURE_AT:
		strcpy_s(name, "Sword of ");
		break;

	case TREASURE_DF:
		strcpy_s(name, "Shield of ");
		break;
	default:
		return false;
	}

	// Append the item name to the string
	strncat_s(name, itemNames[item], 30);
	std::cout << EXTRA_OUTPUT_POS << RESET_COLOR << "You picked up the " << name << std::endl;
	m_powerups.push_back(Powerup(name, 1, 1, 1.1f));

	std::sort(m_powerups.begin(), m_powerups.end(), Powerup::Compare);

	std::cout << INDENT << "Press 'Enter' to continue.";
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	std::cin.get();
	return true;
}