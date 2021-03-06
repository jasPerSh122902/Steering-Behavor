#pragma once

class Agent;
/// <summary>
/// Abstract class for all decisions
/// </summary>
class Decision
{
public:
	/// <summary>
	/// Will check the current condition for that actor
	/// </summary>
	/// <param name="actor">The thing that is being checked</param>
	/// <returns>a a decision that sets the steering force</returns>
	virtual void makeDecision(Agent* actor, float deltaTime) = 0;
};

