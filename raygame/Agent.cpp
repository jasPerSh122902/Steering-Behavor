#include "Agent.h"
#include "MovementComponet.h"
#include "SteeringComponet.h"

void Agent::onAddComponet(Componet* comp)
{
	SteeringComponet* steeringComponet = dynamic_cast<SteeringComponet*>(comp);
	if (steeringComponet)
		m_steeringCompont.addItem(steeringComponet);
	
}

void Agent::start()
{
	m_moveComponet = addComponent<MovementComponet>();
	
}

void Agent::update(float deltaTime)
{
	//gets all frce being applied from the steering behaviours
	for  (int i= 0; i < m_steeringCompont.getLength(); i++)
	{
		m_force = m_force + m_steeringCompont[i]->calculateForce();
	}
	//clamp force is it exveeds the maximum scale
	if (m_force.getMagnitude() > getMaxForce())
	{
		m_force = m_force.getNormalized() * getMaxForce();
	}
	//apply force to velocity
	getMoveComponet()->setVelocity(getMoveComponet()->getVelocity() + m_force * deltaTime);
}
