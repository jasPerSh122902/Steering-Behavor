#include "SeekComponet.h"
#include "Actor.h"
#include "MovementComponet.h"

SeekComponet::SeekComponet( Actor* targetActor,Actor* owner, int orderValue) : SteeringComponet::SteeringComponet(owner)
{
	m_targetActor = targetActor;
	m_seekForce = 150;
	m_orderValue = orderValue;
}

void SeekComponet::update(float deltaTime)
{
	//gets the distence between the owner and the target
	m_desiredVelocity = MathLibrary::Vector2::normalize(getTarget()->getTransform()->getWorldPosition() - getOwner()->getTransform()->getWorldPosition()) * m_seekForce;
	//makes a pointer to the movecomponet and casts it as a movement componet pointer...
	//..to get its owners componet that is "MoveComponet"
	MovementComponet* movement = new MovementComponet(movement->getOwner());
	movement->getOwner()->getComponent<MovementComponet>();
	//This way will break the reatreat and seek so dont do it
	m_sterringForce = m_desiredVelocity - movement->getVelocity();//will allow the force to be the desired velocity subtracted by the owners velocity
	//give the thing movement and add it to the vector
	movement->setVelocity(movement->getVelocity() + m_sterringForce * deltaTime);
}

