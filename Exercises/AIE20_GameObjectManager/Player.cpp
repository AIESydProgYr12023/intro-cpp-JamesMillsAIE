#include "Player.h"

#include "Transform.h"

Player::Player(vec2 _position) 
	: GameObject(_position, 0, { 50, 50 })
{
	tint = RED;
}

void Player::Update(float _dt)
{
	if (IsKeyDown(KEY_E))
		m_transform->rotation += 10.f * _dt;

	if (IsKeyDown(KEY_Q))
		m_transform->rotation -= 10.f * _dt;

	if (IsKeyDown(KEY_W))
		m_transform->position += m_transform->ForwardVector();

	if (IsKeyDown(KEY_S))
		m_transform->position -= m_transform->ForwardVector();
}

void Player::Draw()
{
	Rectangle rect
	{
		m_transform->position.x,
		m_transform->position.y,
		m_transform->scale.x,
		m_transform->scale.y
	};

	Vector2 origin
	{
		m_transform->scale.x * 0.5f,
		m_transform->scale.y * 0.5f
	};

	DrawRectanglePro(rect, origin, m_transform->rotation, tint);
}