#pragma once
#include "Decision.h"

/// <summary>
/// Yes or No decicions
/// </summary>
class BooleanDecisions :
	public Decision
{
public:
	/// <param name="left">The left of the node</param>
	/// <param name="right">the right of the node</param>
	BooleanDecisions(Decision* left = nullptr, Decision* right = nullptr);
	
	/// <summary>
	/// Checks the condition and transtions to a different decision based on the return value
	/// </summary>
	/// <param name="actor">the agnet that this decision tree is attacked to</param>
	/// <param name="deltaTime">A varibale that can be used for Time between frames</param>
	virtual void makeDecision(Agent* actor, float deltaTime) override;

	/// <summary>
	/// Checks if a certain condition has been met and returns the result
	/// </summary>
	virtual bool checkCondition(Agent* actor, float deltaTime) { return false; };

private:
	//left is no and right is yes
	Decision* m_no;
	Decision* m_yes;
};

