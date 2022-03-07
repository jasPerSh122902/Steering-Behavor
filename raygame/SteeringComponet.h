#pragma once
#include "Componet.h"
#include <Vector2.h>
class Actor;
class Agent;

class SteeringComponet :
	public Componet
{
public:
	SteeringComponet() { m_targetActor = nullptr; m_steeringForce = 0; }
	SteeringComponet(Actor* actor, float sterringForce) { m_targetActor = actor; m_steeringForce = sterringForce; }//initialiezes target
	//putting that 0 makes me make a new instence of the calclate force at all times
	virtual MathLibrary::Vector2 calculateForce() = 0;//override this is inherited steering behaviour here
	Actor* getTarget() {return m_targetActor; }//gets the target actor this steering behaviour is using to calculate force
	void setTarget(Actor* targetActor) { m_targetActor = targetActor; }//sets the target actor to this steering behaviour will be using to calvulate force
	float getSteeringForce() { return m_steeringForce; };
	void setSteeringForce(float steeringForce) { m_steeringForce = steeringForce; };
	void start() override;
	Agent* getAgent() { return (Agent*)getOwner(); }
private:
	Actor* m_targetActor = nullptr;
	float m_steeringForce = 0;
	
};

