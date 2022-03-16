#pragma once
#include "Agent.h"

class Enemy :
	public Agent
{
public:
	Enemy(float x, float y, const char* name, float maxSpeed,float maxForce, Actor* targetActor);
	~Enemy() {}

	void start() override;
	void update(float deltaTime) override;
	
	bool getTargetInRange();

	Actor* getTarget() { return m_targetActor; }
	void setTarget(Actor* targetActor) { m_targetActor = targetActor; }

	bool getIsAgressive() { return m_isAgressive; }
	void setAgressive(bool isAgressive) {m_isAgressive = isAgressive ; }

private:
	Actor* m_targetActor;
	bool m_isAgressive;
};

