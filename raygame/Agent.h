#pragma once
#include "Actor.h"
#include "Player.h"
class Agent :
	public Actor
{
private:
	//actors that are seeked
	Actor* m_targetActor;
	Player* m_playerpointer;
public:
	//basic constuctor for the agent
	Agent();
	~Agent();

	//tring to get its actor
	Actor* getTarget() { return m_targetActor; }
};
