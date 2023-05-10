#include "Transform.h"

#include <cmath>

AIETransform::AIETransform()
	: position({ 0, 0 }), rotation(0), scale({ 10, 10 })
{
}

AIETransform::AIETransform(vec2 _pos)
	: position(_pos), rotation(0), scale({ 10, 10 })
{
}

AIETransform::AIETransform(vec2 _pos, float _rotation)
	: position(_pos), rotation(_rotation), scale({ 10, 10 })
{
}

AIETransform::AIETransform(vec2 _pos, float _rotation, vec2 _scale)
	: position(_pos), rotation(_rotation), scale(_scale)
{
}

Vector2 AIETransform::RayPosition()
{
	return { position.x, position.y };
}

Vector2 AIETransform::RayScale()
{
	return { scale.x, scale.y };
}

vec2 AIETransform::ForwardVector()
{
	float radians = (PI / 180.f) * rotation;
	return { cosf(radians), sinf(radians) };
}
