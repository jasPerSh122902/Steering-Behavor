#pragma once
#include "Actor.h"
#include "DynamicArray.h"
#include <Vector2.h>
class SteeringComponet;
class MovementComponet;

class Agent :
	public Actor
{
private:
	
	//actors that are seeked
	float m_maxForce;//the force vector should not be allowed to have a magnitude greater than this vlaue
	MovementComponet* m_moveComponet;//stroes the mov e ocmponet attacked to the agent in order to get access to its velocity
	DynamicArray<SteeringComponet*> m_steeringCompont;//an array containing all steering componets attacked to the agent
	MathLibrary::Vector2 m_force;
public:
	Agent(float x, float y, const char* name, float maxSpeed, float maxForce);
	MovementComponet* getMoveComponet() { return m_moveComponet; }
    void onAddComponet(Componet* comp)override;//used to add new steering componets array
	float getMaxForce() { return m_maxForce; }
	void setMaxForce(float maxForce) { m_maxForce = maxForce; }
	void start() override;//initializes move componet
	void update(float deltaTime) override;//gets the sum of all forces being acted on the agent and applies it to its velocity
};

