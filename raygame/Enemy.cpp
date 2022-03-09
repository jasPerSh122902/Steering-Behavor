#include "Enemy.h"
#include "SeekComponet.h"
#include "RetreatComponet.h"
#include "RomingComponet.h"

Enemy::Enemy(float x, float y, const char* name,float speed, int maxHealth, Actor* targetActor) :
	Character(x, y, name, speed, maxHealth)
{
	m_targetActor = targetActor;
}



void Enemy::start()
{
	Character::start();
	//Copy the agents update and start
}

void Enemy::update(float deltaTime)
{
	
	Character::update(deltaTime);//called the characters update
}
