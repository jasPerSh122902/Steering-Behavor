#pragma once
#include "Actor.h"
#include "DynamicArray.h"
#include "SteeringComponet.h"
#include "MovementComponet.h"

class Agent :
	public Actor
{
private:
	//actors that are seeked
	float m_maxForce;
	float m_maxVelocity;
	float m_force;
	MovementComponet* m_moveComponet;
	DynamicArray<SteeringComponet* > m_steeringCompont;
public:
	//basic constuctor for the agent
	Agent();
	~Agent();
	void onAddComponet(Componet* comp);
	float getforce() { return m_force; }
	float setForce(float force) { m_force = force; }
};

