#include "RetreatComponet.h"
#include "Actor.h"
#include "MovementComponet.h"

RetreatComponet::RetreatComponet(Actor* targetActor, Actor* owner) 
{
	m_targetActor = targetActor;
	m_seekForce = 150;
}

void RetreatComponet::update(float deltaTime)
{
	//gets the distence between the owner and the target
	m_desiredVelocity = MathLibrary::Vector2::normalize(getOwner()->getTransform()->getWorldPosition() - getTarget()->getTransform()->getWorldPosition()) * m_seekForce;
	//makes a pointer to the movecomponet and casts it as a movement componet pointer...
	//..to get its owners componet that is "MoveComponet"

	//will break the seek and retreat
	m_sterringForce = m_desiredVelocity - m_movementComp->getVelocity();//will allow the force to be the desired velocity subtracted by the owners velocity
	//give the thing movement and add it to the vector
	m_movementComp->setVelocity(m_movementComp->getVelocity() + m_sterringForce * deltaTime);
}
