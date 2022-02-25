#pragma once
#include "Componet.h"
#include "Actor.h"
#include "Transform2D.h"
class SteeringComponet :
	public Componet
{
public:
	SteeringComponet(Actor* actor);
	void update(float deltaTime) override;
	MathLibrary::Vector2 calculateForce();
private:
	MathLibrary::Vector2 m_force;
	Actor* m_targetActor;
};

