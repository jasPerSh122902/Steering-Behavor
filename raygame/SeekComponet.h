#pragma once
#include "Componet.h"
#include "Transform2D.h"
#include "MovementComponet.h"
#include "Transform2D.h"
class SeekComponet :
	public Componet
{
private:
	float m_seekForce;
	Actor* m_targetActor;
	MovementComponet* m_movementComp;
	MathLibrary::Vector2 m_sterringForce;
	MathLibrary::Vector2 m_desiredVelocity;
	MathLibrary::Vector2 m_currentVelocity;
public:
	SeekComponet( Actor* targetActor);

	Actor* getTarget() const { return m_targetActor; }
	void setTarget(Actor* targetActor) { m_targetActor = targetActor; }

	float getForce() { return  m_seekForce; }
	void setForce(float seekForce) { m_seekForce = seekForce; }

	void update(float deltaTime) override;
};
