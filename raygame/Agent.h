#pragma once
#include "Actor.h"
#include "Sprite.h"
#include "Transform2D.h"
#include "Movement.h"
#include "Sprite.h"
#include "SeekComponet.h"
#include "Player.h"
class Agent :
	public Actor
{
private:
	Agent* m_agent;
	Actor* m_targetActor;
	Sprite* m_spriteComponet;
	Player* m_player;


public:
	Agent(int x, int y, const char* name, Actor* targetActor);


	 /// <summary>
    /// Called during the first update after an actor is added to a scene.
    /// </summary>
	void start() override;
	void end() override;
	void update(float deltaTime);
};

