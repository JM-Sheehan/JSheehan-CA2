#pragma once
#include "Component.hpp"
class HealthCmpt : public Component
{
public:
	HealthCmpt(int startingHealth);

	void TakeDamage(int damage);

	void Heal(int healing);

	void increaseMax(int increase);

private:
	int m_health;
	int m_max;
};

