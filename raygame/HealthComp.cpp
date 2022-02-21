#include "HealthComp.h"

HealthComp::HealthComp(int maxHealth, Actor* owner)
{
	m_maxHealth = maxHealth;
	m_currentHealth = maxHealth;
}

HealthComp::~HealthComp()
{

}

void HealthComp::start()
{
	m_currentHealth = m_maxHealth;
}

void HealthComp::update(float deltaTime)
{
	if (m_currentHealth <= 0)
		getOwner()->end();
}

void HealthComp::onCollision(Actor* actor)
{
	if (actor->getName() == "Enemy1")
	{
		m_currentHealth--;
	}
}
