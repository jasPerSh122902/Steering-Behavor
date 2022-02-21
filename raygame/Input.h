#pragma once
#include "Componet.h"
#pragma once
#include "Componet.h"
#include <raylib.h>
#include <Vector2.h>

class Input :
	public Componet
{
public:
	Input(const char* name = "InputComponet") : Componet::Componet(name) {}

	MathLibrary::Vector2 getMoveAxis();

private:

	//actions keys that are actives
	RAYLIB_H::KeyboardKey m_action1key = RAYLIB_H::KeyboardKey::KEY_SPACE;
	RAYLIB_H::KeyboardKey m_action2key = RAYLIB_H::KeyboardKey::KEY_P;
	RAYLIB_H::KeyboardKey m_action3key = RAYLIB_H::KeyboardKey::KEY_ENTER;
	RAYLIB_H::KeyboardKey m_action4key = RAYLIB_H::KeyboardKey::KEY_BACKSPACE;
};

