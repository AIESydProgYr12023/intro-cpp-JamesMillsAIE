#pragma once

#include "Point2D.h"

class Player
{
public:
	Player();
	Player(int _x, int _y);
	~Player();


	void SetPosition(Point2D _position);

	Point2D GetPosition();

	void Draw();

	bool ExecuteCommand(int _command);

private:
	Point2D m_mapPosition;
};

