#include "RetreatComponet.h"
#include "Actor.h"
#include "MovementComponet.h"

RetreatComponet::RetreatComponet(Actor* targetActor)
{
	m_targetActor = targetActor;
	m_seekForce = 150;
}

void RetreatComponet::update(float deltaTime)
{

	m_desiredVelocity = MathLibrary::Vector2::normalize(getOwner()->getTransform()->getWorldPosition() - getTarget()->getTransform()->getWorldPosition()) * m_seekForce;

	MovementComponet* movement = dynamic_cast<MovementComponet*>(getOwner()->getComponent("MoveComponet"));

	//m_movementComp->getOwner()->getComponent("MoveComponet");
	m_sterringForce = m_desiredVelocity - movement->getVelocity();

	movement->setVelocity(movement->getVelocity() + m_sterringForce * deltaTime);
}
