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
	Character::start();//called start for the charactor
	//added this to the enemy to seek the target who is the player
	SeekComponet* seekBehaveor = new SeekComponet(m_targetActor);
	addComponent(seekBehaveor);
	//added this to the enemy to run away forom the target who is the player
	//RetreatComponet* retreatComponet = new RetreatComponet(m_targetActor);
	//addComponent(retreatComponet);
}

void Enemy::update(float deltaTime)
{
	Character::update(deltaTime);//called the characters update
}