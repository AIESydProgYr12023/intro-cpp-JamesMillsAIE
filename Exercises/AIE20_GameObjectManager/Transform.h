#pragma once

#include <glm/vec2.hpp>
#include <raylib.h>

using glm::vec2;

class AIETransform
{
public:
	vec2 position;
	float rotation;
	vec2 scale;

public:
	AIETransform();
	AIETransform(vec2 _pos);
	AIETransform(vec2 _pos, float _rotation);
	AIETransform(vec2 _pos, float _rotation, vec2 _scale);

	Vector2 RayPosition();
	Vector2 RayScale();
	vec2 ForwardVector();

};

