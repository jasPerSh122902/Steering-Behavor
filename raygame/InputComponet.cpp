#include "InputComponet.h"
#include "Actor.h"
#include "Transform2D.h"

InputComponet::InputComponet(Actor* owner) : Componet::Componet("Input Componet")
{}

MathLibrary::Vector2 InputComponet::getMoveAxis()
{
	//get the direction for the individual asis------------------------------------
	float xDirection = -RAYLIB_H::IsKeyDown(m_left) + RAYLIB_H::IsKeyDown(m_right);
	float yDirection = RAYLIB_H::IsKeyDown(m_down) - RAYLIB_H::IsKeyDown(m_up);
	//-----------------------------------------------------------------------------
	//returns a new vector representing the moved direction
	return MathLibrary::Vector2(xDirection, yDirection);
}

void InputComponet::update(float deltaTime)
{
	if (getMoveAxis().getMagnitude() > 0)//if the moveaxis's magnitude is greater than 0
		getOwner()->getTransform()->setForward(getMoveAxis());//set the owners forward to the move axis
}
