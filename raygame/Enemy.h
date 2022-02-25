#pragma once
#include "Charactor.h"
#include "MovementComponet.h"
#include "RetreatComponet.h"

class Enemy :
	public Character
{
public:
	Enemy(float x, float y, const char* name, float speed, int maxHealth, Actor* targetActor);
	~Enemy() {}

	void start() override;
	void update(float deltaTime) override;

private:
	Actor* m_targetActor;
	MovementComponet* m_moveMentComponet;
	RetreatComponet* m_retreatComponet;
};

