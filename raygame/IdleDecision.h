#pragma once
#include "Decision.h"

class IdleDecision :
	public Decision
{
public:
	/// <summary>
	/// Will check the current condition for that actor
	/// </summary>
	/// <param name="actor">The thing that is being checked</param>
	/// <returns>a a decision that sets the steering for to 0</returns>
	void makeDecision(Agent* actor, float deltaTime) override;
};

