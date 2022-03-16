#pragma once
#include "Decision.h"
class SeekDecision :
	public Decision
{
public:
	/// <summary>
	/// Will check the current condition for that actor
	/// </summary>
	/// <param name="actor">The thing that is being checked</param>
	/// <returns>a a decision that sets the steering force</returns>
	void makeDecision(Agent* actor, float deltaTime) override;
};

