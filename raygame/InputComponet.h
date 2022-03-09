#pragma once
#include "Componet.h"
#include <raylib.h>
#include <Vector2.h>

class InputComponet :
	public Componet
{
public:
	InputComponet() : Componet::Componet() {}

	MathLibrary::Vector2 getMoveAxis();

private:

	//The keys on the key board using the ray lib Key binds and I put them as Varibles with direciton
	RAYLIB_H::KeyboardKey m_up = RAYLIB_H::KeyboardKey::KEY_W;
	RAYLIB_H::KeyboardKey m_left = RAYLIB_H::KeyboardKey::KEY_A;
	RAYLIB_H::KeyboardKey m_down = RAYLIB_H::KeyboardKey::KEY_S;
	RAYLIB_H::KeyboardKey m_right = RAYLIB_H::KeyboardKey::KEY_D;
};

