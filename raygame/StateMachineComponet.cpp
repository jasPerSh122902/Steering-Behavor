#include "StateMachineComponet.h"
#include "Actor.h"
#include "SeekComponet.h"
#include "RomingComponet.h"
#include "Transform2D.h"

void StateMachineComponet::start()
{
	Componet::start();

	m_seekComponet = getOwner()->getComponent<SeekComponet>();
	m_seekForce = m_seekComponet->getSteeringForce();

	m_romingComponet = getOwner()->getComponent<RomingComponet>();
	m_romingForce = m_romingComponet->getSteeringForce();

	m_currentState = IDLE;
}

void StateMachineComponet::update(float deltaTime)
{

	Componet::update(deltaTime);
	MathLibrary::Vector2 targetPos = m_seekComponet->getTarget()->getTransform()->getWorldPosition();
	MathLibrary::Vector2 ownerPos = getOwner()->getTransform()->getWorldPosition();

	float distanceFromTarget = (targetPos - ownerPos).getMagnitude();

	bool targetInRange = distanceFromTarget <= m_seekRange;
	switch(m_currentState)
	{
	case IDLE:
		m_seekComponet->setSteeringForce(0);
		m_romingComponet->setSteeringForce(0);

		if(targetInRange)
			setCurrentState(SEEKING);
		break;
	case Roming:
		m_seekComponet->setSteeringForce(0);
		m_romingComponet->setSteeringForce(m_romingForce);

		if (targetInRange)
			setCurrentState(SEEKING);
		break;
	case SEEKING:
		m_seekComponet->setSteeringForce(m_seekForce);
		m_romingComponet->setSteeringForce(0);

		if (!targetInRange)
			setCurrentState(Roming);
		break;
	}
}
