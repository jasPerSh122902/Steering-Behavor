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
	//this is for example
	//MovementComponet* m_movementComp;
	
	//these are the two forces that are used--
	MathLibrary::Vector2 m_sterringForce;
	MathLibrary::Vector2 m_desiredVelocity;
	//----------------------------------------
public:
	SeekComponet(Actor* targetActor);//takes in a targe to work

	Actor* getTarget() const { return m_targetActor; }//gets u back the target that is has
	void setTarget(Actor* targetActor) { m_targetActor = targetActor; }//set that target that it takes in

	float getForce() { return  m_seekForce; }//gets u back the force it has
	void setForce(float seekForce) { m_seekForce = seekForce; }//sets the force to the force that is put in

	void update(float deltaTime) override;
};

