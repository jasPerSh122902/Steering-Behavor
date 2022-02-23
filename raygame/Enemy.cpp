#include "Enemy.h"
#include "SeekComponet.h"
#include "RetreatComponet.h"

Enemy::Enemy(float x, float y, const char* name,float speed, int maxHealth, Actor* targetActor) :
	Character(x, y, name, speed, maxHealth)
{
	m_targetActor = targetActor;
}



void Enemy::start()
{
	Character::start();

	/*SeekComponet* seekBehaveor = new SeekComponet(m_targetActor);
	addComponent(seekBehaveor);*/
	RetreatComponet* retreatComponet = new RetreatComponet(m_targetActor);
	addComponent(retreatComponet);
}

void Enemy::update(float deltaTime)
{
	Character::update(deltaTime);
}