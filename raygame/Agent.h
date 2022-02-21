#pragma once
#include "Actor.h"
#include "Movement.h"
#include "Sprite.h"
class Agent :
	public Actor
{
private:
	Agent* m_agent;
	Actor* m_targetActor;
	Movement* m_movementComp;
	Sprite* m_spriteComponet;
	int m_x;
	int m_y;
public:
	Agent(int x , int y , const char * name);
	void getTargetActor() { m_targetActor; }

	void setTargetActor(Actor* targetActor);

	 /// <summary>
    /// Called during the first update after an actor is added to a scene.
    /// </summary>
    void start() override;

	void update(float deltaTime) override;
};

