#include "Input.h"


MathLibrary::Vector2 Input::getMoveAxis()
{
	//get the direction for the individual asis
	float xDirection = -RAYLIB_H::IsKeyDown(KEY_A) + RAYLIB_H::IsKeyDown(KEY_D);
	float yDirection = -RAYLIB_H::IsKeyDown(KEY_W) + RAYLIB_H::IsKeyDown(KEY_S);

	//returns a new vector representing the moved direction
	return MathLibrary::Vector2(xDirection, yDirection);
}
