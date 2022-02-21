#pragma once
#include "Componet.h"
#include <Vector2.h>
#include "Player.h"

class SeekComponet :
	public Componet
{
private:
	//base comstroctor for the movement
	SeekComponet(const char* name = "SeekComponet") : Componet::Componet(name) {}
	void update(float deltaTime) override;

	/// <summary>
	/// Gets the current speed and direction of theis actor in the form of a velocity
	/// </summary>
	/// <returns></returns>
	MathLibrary::Vector2 getVelocity() { return m_velocity; }

	/// <summary>
	/// Gets the current speed and direction of theis actor in the form of a velocity
	/// </summary>
	/// <returns></returns>
	MathLibrary::Vector2 setVelocity(MathLibrary::Vector2 velocity) {m_velocity = velocity; }

	int getMaxVelocity() { m_maxSpeed; }

	int getMaxVelocity(float maxSpeed) { m_maxSpeed = maxSpeed; }
public:
	float m_maxSpeed;
	MathLibrary::Vector2 m_velocity;
	Player m_player;
};

