#pragma once

#include "GameObject.h"

class Player : public GameObject
{
public:
	Player(vec2 _position);

	virtual void Update(float _dt) override;
	virtual void Draw() override;

};

