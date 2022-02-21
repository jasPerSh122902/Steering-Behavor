#include "Movement.h"
#include "Actor.h"
#include "Transform2D.h"

void Movement::update(float deltaTime)
{
	//add the new vbelocity to the old position to get the new position
	MathLibrary::Vector2 currentPosition = getOwner()->getTransform()->getLocalPosition();

	MathLibrary::Vector2 newPosition = MathLibrary::Vector2((currentPosition.x + (m_velocity.x * deltaTime)), currentPosition.y + (m_velocity.y * deltaTime));

	//set the actors position to be the new position found
	if(newPosition.getMagnitude() > 0)
		getOwner()->getTransform()->setLocalPosition(newPosition);
}
