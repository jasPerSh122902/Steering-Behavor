#include "Movement.h"
#include "Actor.h"
#include "Transform2D.h"

void Movement::update(float deltaTime)
{
	//add the new vbelocity to the old position to get the new position
	MathLibrary::Vector2 newPosition = getOwner()->getTransform()->getLocalPosition() + getVelocity() * deltaTime;

	//set the actors position to be the new position found
	getOwner()->getTransform()->setLocalPosition(newPosition);
}
