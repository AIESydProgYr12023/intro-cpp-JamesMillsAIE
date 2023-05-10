#pragma once

#include <glm/vec2.hpp>
#include <raylib.h>

class AIETransform;

using glm::vec2;

class GameObject
{
public:
	Color tint = RAYWHITE;

public:
	GameObject();
	GameObject(vec2 _position);
	GameObject(vec2 _position, float _rotation);
	GameObject(vec2 _position, float _rotation, vec2 _scale);

	~GameObject();

	virtual void Load() {}
	virtual void Update(float _dt) = 0;
	virtual void Draw() = 0;
	virtual void Unload() {}

protected:
	AIETransform* m_transform;

};

