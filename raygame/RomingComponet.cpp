#include "RomingComponet.h"
#include "MovementComponet.h"
#include "Agent.h"
#include "Transform2D.h"
#include "Actor.h"
#include <time.h>

RomingComponet::RomingComponet(float circleDistance, float circleRadius, float wanderForce) : SteeringComponet(nullptr, wanderForce)
{
	m_radius = circleRadius;
	m_distance = circleDistance;
	std::srand(time(0));
}

MathLibrary::Vector2 RomingComponet::calculateForce()
{
	if (getSteeringForce() == 0)
		return { 0,0 };
	//finds the agnets poitin and heading
	MathLibrary::Vector2 ownerPos = getOwner()->getTransform()->getWorldPosition();//gets the worldposition for the owner or agent
	MathLibrary::Vector2 heading = (getAgent()->getMoveComponet()->getVelocity());//gets the agnets velocity

	//Find the circles position in front of the agent
	m_circlePos = ownerPos + (heading * m_distance);
	//Find a random vector on the circle and scale it up by the radius
	MathLibrary::Vector2 randDirection = MathLibrary::Vector2{getTheRand(), getTheRand()}.normalize() * m_radius;
	//finds the target by adding the random point and circle position
	m_target = randDirection + m_circlePos;
	//seek to the random point
	MathLibrary::Vector2 desiredVelocity = MathLibrary::Vector2::normalize(m_target - ownerPos) * getSteeringForce();
	MathLibrary::Vector2 force = desiredVelocity - getAgent()->getMoveComponet()->getVelocity();

	return force;
}

float RomingComponet::getTheRand()
{
	float m_rand;
	//makes a random number
	m_rand = ((rand() % 201) - 100);
	return m_rand;
}