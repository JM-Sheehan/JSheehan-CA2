#include "HealthCmpt.hpp"

HealthCmpt::HealthCmpt(int startingHealth)
{
	m_health = startingHealth;
}

void HealthCmpt::TakeDamage(int damage)
{
	m_health -= damage;
	if (m_health < 0) {
		m_health = 0;
	}
}

void HealthCmpt::Heal(int healing)
{
	m_health += healing;
	if (m_health > m_max) {
		m_health = m_max;
	}
}

void HealthCmpt::increaseMax(int increase)
{
	m_max += increase;
	Heal(increase);
}
