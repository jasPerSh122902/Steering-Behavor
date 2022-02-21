#include "SeekComponet.h"


SeekComponet::SeekComponet(const char* name, Actor* targetActor)
{
	name = "SeekComponet";
	m_targetActor = targetActor;
}

void SeekComponet::update(float deltaTime)
{

	m_desiredVelocity = MathLibrary::Vector2::normalize(m_targetActor->getTransform()->getLocalPosition() - getOwner()->getTransform()->getLocalPosition()) * m_seekForce;
	m_sterringForce = m_desiredVelocity - m_currentVelocity;

	m_velocity.x += m_sterringForce.x * deltaTime;
	m_velocity.y += m_sterringForce.y * deltaTime;

	m_position.x += m_velocity.x * deltaTime;
	m_position.y += m_velocity.y * deltaTime;
	//return MathLibrary::Vector2(m_position.x, m_position.y);

	getOwner()->getTransform()->setLocalPosition(m_position);
}

