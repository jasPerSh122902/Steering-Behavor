#include "BooleanDecisions.h"
//Will continue to go to the left or the right if the condistion is not me
void BooleanDecisions::makeDecision(Agent* actor, float deltaTime)
{
	if (checkCondition(actor, deltaTime))
	{
		if (m_yes)
			m_yes->makeDecision(actor, deltaTime);

	}
	else 
	{
		if (m_no)
			m_no->makeDecision(actor, deltaTime);
	}
}

BooleanDecisions::BooleanDecisions(Decision* left, Decision* right)
{
	m_no = left;
	m_yes = right;
}
