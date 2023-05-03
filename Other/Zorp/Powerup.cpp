#include "Powerup.h"

#include <iostream>

Powerup::Powerup(const char _name[30], float _health, float _attack, float _defence)
	: m_healthMultiplier(_health), m_attackMultiplier(_attack), m_defenceMultiplier(_defence)
{
	strcpy_s(m_name, _name);
}

Powerup::~Powerup()
{
}

char* Powerup::GetName()
{
	return m_name;
}

float Powerup::GetHealthMultiplier()
{
	return m_healthMultiplier;
}

float Powerup::GetAttackMultiplier()
{
	return m_attackMultiplier;
}

float Powerup::GetDefenceMultiplier()
{
	return m_defenceMultiplier;
}

bool Powerup::Compare(const Powerup& _lhs, const Powerup& _rhs)
{
	return strcmp(_lhs.m_name, _rhs.m_name) < 0;
}
