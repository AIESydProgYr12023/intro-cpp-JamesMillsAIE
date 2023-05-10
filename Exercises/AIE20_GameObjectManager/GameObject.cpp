#include "GameObject.h"

#include "Transform.h"

GameObject::GameObject()
	: m_transform(new AIETransform())
{

}

GameObject::GameObject(vec2 _position)
	: m_transform(new AIETransform(_position))
{
}

GameObject::GameObject(vec2 _position, float _rotation)
	: m_transform(new AIETransform(_position, _rotation))
{
}

GameObject::GameObject(vec2 _position, float _rotation, vec2 _scale)
	: m_transform(new AIETransform(_position, _rotation, _scale))
{
}

GameObject::~GameObject()
{
	delete m_transform;
	m_transform = nullptr;
}