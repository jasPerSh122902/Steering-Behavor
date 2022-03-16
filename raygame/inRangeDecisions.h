#pragma once
#include "BooleanDecisions.h"
class inRangeDecisions :
	public BooleanDecisions
{
public:
	bool checkCondition(Agent* actor, float deltaTime) override;
private:
};

