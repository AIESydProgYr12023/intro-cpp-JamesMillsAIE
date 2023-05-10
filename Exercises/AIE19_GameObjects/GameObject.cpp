#include "GameObject.h"
#include "GameObject.h"

GameObject::GameObject()
	: color(RED), position({ 400, 300 })
{
}

void GameObject::Update(float _dt)
{
	if (IsKeyDown(KEY_W))
	{
		position.y -= 50 * _dt;
	}

	if (IsKeyDown(KEY_S))
	{
		position.y += 50 * _dt;
	}

	if (IsKeyDown(KEY_D))
	{
		position.x += 50 * _dt;
	}

	if (IsKeyDown(KEY_A))
	{
		position.x -= 50 * _dt;
	}
}

void GameObject::Draw()
{
	DrawCircleV(position, 20.f, color);
}
