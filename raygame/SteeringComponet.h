#pragma once
#include "Componet.h"
#include "Actor.h"
class SteeringComponet :
	public Componet
{
public:
	SteeringComponet(Actor* actor);
	void update(float deltaTime) override;
	void calculateForce();
private:
	MathLibrary::Vector2 m_force;
	Actor* m_targetActor;
};

