#include "SeekComponet.h"
#include "Actor.h"
#include "MovementComponet.h"
#include "Transform2D.h"
#include "Agent.h"

MathLibrary::Vector2 SeekComponet::calculateForce()
{
	if (!getTarget())
		return{ 0,0 };

	setSteeringForce(254);

	MathLibrary::Vector2 directionToTarget = (getTarget()->getTransform()->getWorldPosition()
											- getOwner()->getTransform()->getWorldPosition());
	MathLibrary::Vector2 desriedVelocity = directionToTarget.normalize() * getSteeringForce();
																			
	MathLibrary::Vector2 seekForce = directionToTarget - getAgent()->getMoveComponet()->getVelocity();

	return seekForce;
}