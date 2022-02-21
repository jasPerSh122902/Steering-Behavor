#include "Agent.h"
#include "Sprite.h"

Agent::Agent(int x, int y, const char* name)
{
	m_x = x;
	m_y = y;
}

void Agent::setTargetActor(Actor* targetActor)
{
	if (m_targetActor = targetActor)
	{
		m_movementComp->getStarted();
	}
}

void Agent::start()
{
	Actor::start();

	setTargetActor(m_targetActor);

	m_movementComp = dynamic_cast<Movement*>(addComponent(new Movement()));
	m_movementComp->setMaxSpeed(50);
	m_spriteComponet = dynamic_cast<Sprite*>(addComponent(new Sprite("Sprite/Larrot.png")));
}

void Agent::update(float deltaTime)
{
	Actor::update(deltaTime);
	//allows for movement
	MathLibrary::Vector2 moveDirection = m_targetActor->getTransform() - m_agent->getTransform();

	m_movementComp->setVelocity(moveDirection * 300);
}
