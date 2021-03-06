#pragma once
#include "BooleanDecisions.h"
class inRangeDecisions :
	public BooleanDecisions
{
public:
	inRangeDecisions(Decision* left = nullptr, Decision* right = nullptr) : BooleanDecisions(left, right) {};
	/// <summary>
	/// Will check the current condition for that actor to see if it is true or false
	/// </summary>
	/// <param name="actor">The thing that is being checked</param>
	/// <returns>a bool for a true or false</returns>
	bool checkCondition(Agent* actor, float deltaTime) override;
};

