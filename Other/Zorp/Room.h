#pragma once

#include "Point2D.h"

class Room
{
public:
	Room();
	~Room();

	void SetPosition(Point2D _position);
	void SetType(int _type);

	int GetType();
	
	void Draw();
	void DrawDescription();

	bool ExecuteCommand(int _command);

private:
	Point2D m_mapPosition;
	int m_type;

};