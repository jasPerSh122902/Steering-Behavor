#include "DecisionComponent.h"
#include "Decision.h"
#include "Agent.h"

void DecisionComponent::start()
{
	m_owner = dynamic_cast<Agent*>(getOwner());
}
void DecisionComponent::update(float deltaTime)
{
	if (m_owner) 
	{
		m_root->makeDecision(m_owner, deltaTime);
	}
	else
		throw std::exception("Owner was null. Owner is a agent. Decision can only be attacked to agents.");
}
