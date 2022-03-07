#pragma once
#include "SteeringComponet.h"
#include "MovementComponet.h"
#include "Transform2D.h"
class SeekComponet :
	public SteeringComponet
{
private:
	float m_seekForce;
	MovementComponet* movement;
	Actor* m_targetActor;
	int m_orderValue;
public:
	MathLibrary::Vector2 calculateForce() override;
	//SeekComponet(Actor* targetActor ,Actor* owner, int orderValue);//takes in a targe to work

	//Actor* getTarget() const { return m_targetActor; }//gets u back the target that is has
	//void setTarget(Actor* targetActor) { m_targetActor = targetActor; }//set that target that it takes in

	//float getForce() { return  m_seekForce; }//gets u back the force it has
	//void setForce(float seekForce) { m_seekForce = seekForce; }//sets the force to the force that is put in

	//void update(float deltaTime) override;
};

