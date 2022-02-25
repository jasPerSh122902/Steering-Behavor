#pragma once
#include "SteeringComponet.h"
#include "Transform2D.h"
#include "MovementComponet.h"
#include "Transform2D.h"
class RetreatComponet :
    public SteeringComponet
{
private:
	float m_seekForce;
	Actor* m_targetActor;
	MovementComponet* m_movementComp;
	MathLibrary::Vector2 m_sterringForce;
	MathLibrary::Vector2 m_desiredVelocity;
public:
	RetreatComponet(Actor* targetActor, Actor* owner);

	Actor* getTarget() const { return m_targetActor; }
	void setTarget(Actor* targetActor) { m_targetActor = targetActor; }

	float getForce() { return  m_seekForce; }
	void setForce(float seekForce) { m_seekForce = seekForce; }

	void setMovementComp(MovementComponet* movemMentComp) { m_movementComp = movemMentComp; }

	void update(float deltaTime) override;
};

