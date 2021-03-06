#include "InputComponet.h"
#include "Transform2D.h"

MathLibrary::Vector2 InputComponet::getMoveAxis()
{
	//get the direction for the individual asis------------------------------------
	float xDirection = -RAYLIB_H::IsKeyDown(m_left) + RAYLIB_H::IsKeyDown(m_right);
	float yDirection = RAYLIB_H::IsKeyDown(m_down) - RAYLIB_H::IsKeyDown(m_up);
	//-----------------------------------------------------------------------------
	//returns a new vector representing the moved direction
	return MathLibrary::Vector2(xDirection, yDirection);
}
