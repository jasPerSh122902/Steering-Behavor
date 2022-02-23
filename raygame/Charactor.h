#pragma once
#include "Actor.h"
#include <Vector2.h>
class MovementComponet;


class Character :
	public Actor
{
public:
	Character(float x, float y, const char* name, float speed, int maxHealth);
	~Character();

	void start();
	void update(float deltaTime);
	void draw();
	float getSpeed() { return m_speed; }
	MovementComponet* getTheMoveComponet() { return m_moveComponet; }

private:
	int m_speed;
	int m_maxHealth;
	float m_firingCooldown;
	MovementComponet* m_moveComponet;
};
