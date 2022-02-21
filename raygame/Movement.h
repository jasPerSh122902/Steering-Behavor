#pragma once
#include "Componet.h"
#include <Vector2.h>



class Movement :
	public Componet
{
public:
	//base comstroctor for the movement
	Movement(const char* name = "MoveComponet") : Componet::Componet(name) {}

	/// <summary>
	/// Gets the current speed and direction of theis actor in the form of a velocity
	/// </summary>
	/// <returns></returns>
	MathLibrary::Vector2 getVelocity() { return m_velocity; }
	/// <summary>
	/// sets the current speed and direction of this actor.
	/// </summary>
	/// <param name="velocity"></param>
	void setVelocity(MathLibrary::Vector2 velocity) { m_velocity = velocity; }

	//gets the max speed of the actor velocity vector
	float getMaxSpeed() { return m_maxSpeed; }
	/// <summary>
	/// sets the maximum magnitude of this actors velocity vector
	/// </summary>
	/// <param name="maxSpeed"></param>
	void setMaxSpeed(float maxSpeed) { m_maxSpeed = maxSpeed; }

	//Inherited from componet class
	void update(float deltaTime) override;

private:

	float m_maxSpeed;
	MathLibrary::Vector2 m_velocity;


};