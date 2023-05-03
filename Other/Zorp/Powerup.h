#pragma once

class Powerup
{
public:
	Powerup(const char _name[30], float _health, float _attack, float _defence);
	~Powerup();

	char* GetName();
	float GetHealthMultiplier();
	float GetAttackMultiplier();
	float GetDefenceMultiplier();

	static bool Compare(const Powerup& _lhs, const Powerup& _rhs);

private:
	char m_name[30];

	float m_healthMultiplier;
	float m_attackMultiplier;
	float m_defenceMultiplier;

};