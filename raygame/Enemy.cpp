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
	//called start for the charactor
	//added this to the enemy to seek the target who is the player
	/*SeekComponet* seekBehaveor = new SeekComponet(m_targetActor,this, 3);
	addComponent(seekBehaveor);*/
	//added this to the enemy to run away forom the target who is the player
	//m_retreatComponet = dynamic_cast<RetreatComponet*>(addComponent(new RetreatComponet(m_targetActor)));
	/*RetreatComponet* retreatComponet = new RetreatComponet(m_targetActor, this);
	addComponent(retreatComponet);*/
	/*RomingComponet* romingComponet = new RomingComponet(this,m_targetActor, 50, 6);
	addComponent(romingComponet);*/
	m_moveMentComponet->setVelocity({m_moveMentComponet->getVelocity().x,m_moveMentComponet->getVelocity().y});
}

void Enemy::update(float deltaTime)
{
	
	Character::update(deltaTime);//called the characters update
}
