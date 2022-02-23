#pragma once
#include "Componet.h"
#include <raylib.h>
#include <Vector2.h>

class InputComponet :
	public Componet
{
public:
	InputComponet(Actor* owner);

	MathLibrary::Vector2 getMoveAxis();
	void update(float deltaTime) override;

private:

	//actions keys that are actives
	RAYLIB_H::KeyboardKey m_up = RAYLIB_H::KeyboardKey::KEY_W;
	RAYLIB_H::KeyboardKey m_left = RAYLIB_H::KeyboardKey::KEY_A;
	RAYLIB_H::KeyboardKey m_down = RAYLIB_H::KeyboardKey::KEY_S;
	RAYLIB_H::KeyboardKey m_right = RAYLIB_H::KeyboardKey::KEY_D;
};

