#pragma once

#include "Point2D.h"
#include "Powerup.h"
#include <vector>

using std::vector;

class Player
{
public:
	Player();
	Player(int _x, int _y);
	~Player();

	void SetPosition(Point2D _position);

	Point2D GetPosition();

	void Draw();

	bool ExecuteCommand(int _command, int _roomType);

private:
	bool Pickup(int _roomType);

private:
	Point2D m_mapPosition;

	vector<Powerup> m_powerups;

	int m_healthPoints;
	int m_attackPoints;
	int m_defencePoints;

};

