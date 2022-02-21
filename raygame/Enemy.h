#pragma once
#include "Actor.h"
class Input;
class Movement;
class Sprite;

class Enemy :
	public Actor
{
public:
	Enemy(float x, float y, const char* name, Actor* targetActor);
	~Enemy() {}

	void start() override;
	void update(float deltaTime) override;

private:
	Actor* m_targetActor;
	Input* m_inputComponet;
	Movement* m_movementComponet;
	Sprite* m_spriteComponet;
};

