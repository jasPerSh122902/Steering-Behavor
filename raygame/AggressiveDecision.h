#pragma once
#include "BooleanDecisions.h"

class AggressiveDecision :
	public BooleanDecisions
{
public:
	AggressiveDecision(Decision* left = nullptr, Decision* right = nullptr) : BooleanDecisions(left, right) {};
	/// <summary>
	/// <summary>
	/// Will check the current condition for that actor to see if it is true or false
	/// </summary>
	/// <param name="actor">The thing that is being checked</param>
	/// <returns>a bool for a true or false</returns>
	bool checkCondition(Agent* actor, float deltaTime) override;
};

