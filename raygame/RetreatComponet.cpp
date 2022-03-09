#include "RetreatComponet.h"
#include "Actor.h"
#include "MovementComponet.h"
#include "Transform2D.h"
#include "Agent.h"



MathLibrary::Vector2 RetreatComponet::calculateForce()
{
	if (!getTarget())
		return{ 0,0 };

	setSteeringForce(254);

	MathLibrary::Vector2 directionToTarget = (getOwner()->getTransform()->getWorldPosition()
		- getTarget()->getTransform()->getWorldPosition());
	MathLibrary::Vector2 desriedVelocity = directionToTarget.normalize() * getSteeringForce();

	MathLibrary::Vector2 seekForce = directionToTarget - getAgent()->getMoveComponet()->getVelocity();

	return seekForce;
}
