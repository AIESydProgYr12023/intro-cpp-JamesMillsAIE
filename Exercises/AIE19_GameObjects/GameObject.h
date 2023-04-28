#pragma once

#include <raylib.h>
#include <raymath.h>

class GameObject
{
public:
	GameObject();

	void Update(float _dt);
	void Draw();

	Color color;
	Vector2 position;

};