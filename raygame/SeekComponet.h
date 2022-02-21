#pragma once
#include "Componet.h"
#include "Transform2D.h"
#include "Player.h"
#include "Movement.h"
#include "Transform2D.h"
class SeekComponet :
	public Componet
{
private:
	int m_maxVelocity;
	float m_seekForce = 45;
	Player* m_player;
	Actor* m_targetActor;
	Movement* m_movementComp;
	MathLibrary::Vector2 m_sterringForce;
	MathLibrary::Vector2 m_desiredVelocity;
	MathLibrary::Vector2 m_currentVelocity;
	MathLibrary::Vector2 m_velocity;
	MathLibrary::Vector2 m_position;
public:
	SeekComponet(const char* name, Actor* targetActor);

	void update(float deltaTime) override;
};

