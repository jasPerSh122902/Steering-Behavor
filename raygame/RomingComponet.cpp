#include "RomingComponet.h"
#include "MovementComponet.h"
#include "Actor.h"
#include <iostream>
#include <time.h>

RomingComponet::RomingComponet(Actor* owner,Actor* targetActor, int radius, int orderValue) : SteeringComponet::SteeringComponet(owner)
{
	m_owner = owner;
	m_radius = radius;
	m_orderValue = orderValue;
	m_targetActor = targetActor;
}

RomingComponet::~RomingComponet()
{}

void RomingComponet::update(float deltaTime)
{
	//made a bool that allow the information to start
	bool m_alowedToMove2 = true;
	while (m_alowedToMove2)
	{
		bool m_alowedToMove = true;

		//made the circle
		DrawCircle(getOwner()->getTransform()->getWorldPosition().x + 55, getOwner()->getTransform()->getWorldPosition().y + 55, m_radius, YELLOW);
		if (m_alowedToMove)
		{
			//How to do (find a direction)
			//then normalize
			//scale it up by the radius
			m_desiredVelocity = { getOwner()->getTransform()->getWorldPosition().x + getTheRand(), getOwner()->getTransform()->getWorldPosition().y + getTheRand() };
			MovementComponet* movement = new MovementComponet(m_owner);
			movement->getOwner()->getComponent<MovementComponet>();
			//This way will break the reatreat and seek so dont do it
			m_sterringForce = m_desiredVelocity - movement->getVelocity();//will allow the force to be the desired velocity subtracted by the owners velocity
			//give the thing movement and add it to the vector
			movement->setVelocity(movement->getVelocity() + m_sterringForce * deltaTime);
			
		}
		m_alowedToMove2 = false;
	}
}

int RomingComponet::getTheRand()
{
	int m_rand;
	//makes the rand only able to go to the radius
	std::srand(time(0));
	//makes two numbers for me
	for (int i = 0; i < rand(); i++)
		m_rand = ((rand() % m_radius) - 30);
	return m_rand;
}

