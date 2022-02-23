#include "MovementComponet.h"
#include "Actor.h"
#include "Transform2D.h"
#include "Componet.h"

MovementComponet::MovementComponet(const char* name) : Componet::Componet(name)
{
	m_maxSpeed = 100;
	m_velocity = MathLibrary::Vector2(0, 0);
}

void MovementComponet::update(float deltaTime)
{

	if (m_velocity.getMagnitude() > m_maxSpeed){
		m_velocity = m_velocity.getNormalized() * m_maxSpeed;
	}
		//add the new vbelocity to the old position to get the new position
		MathLibrary::Vector2 currentPosition = getOwner()->getTransform()->getLocalPosition();

		MathLibrary::Vector2 forward = getOwner()->getTransform()->getForward();

		MathLibrary::Vector2 newPosition = MathLibrary::Vector2((currentPosition.x + (m_velocity.x * deltaTime)),
			currentPosition.y + (m_velocity.y * deltaTime));

		//set the actors position to be the new position found
		if (newPosition.getMagnitude() > 0)
			getOwner()->getTransform()->setLocalPosition(newPosition);
	
}
