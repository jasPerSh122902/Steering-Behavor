#pragma once
#include "Agent.h"

class RetreatComponet;
class Enemy :
	public Agent
{
public:
	Enemy(float x, float y, const char* name, float maxSpeed,float maxForce, Actor* targetActor);
	~Enemy() {}

	void start() override;
	void update(float deltaTime) override;

	Actor* getTarget() { return m_targetActor; }
	void setTarget(Actor* targetActor) { m_targetActor = targetActor; }

private:
	Actor* m_targetActor;
};

