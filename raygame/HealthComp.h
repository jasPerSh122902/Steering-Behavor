#pragma once
#include "Componet.h"
#include "Actor.h"
class HealthComp :
	public Componet
{
public:
	HealthComp(int maxHealth, Actor* owner);
	~HealthComp();

	void start() override;
	void update(float deltaTime) override;

	void onCollision(Actor* actor);

private:
	int m_maxHealth;
	int m_currentHealth;
};

