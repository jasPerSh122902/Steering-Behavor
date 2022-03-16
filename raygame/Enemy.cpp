#include "Enemy.h"
#include "SeekComponet.h"
#include "RetreatComponet.h"
#include "RomingComponet.h"
#include "SpriteComponet.h"
#include "Transform2D.h"

Enemy::Enemy(float x, float y, const char* name, float maxSpeed, float maxForce, Actor* targetActor) : Agent(x , y , name , maxSpeed , maxForce)
{
	m_targetActor = targetActor;
}

void Enemy::start()
{
	Agent::start();

	//adds spriteComponent
	getTransform()->setScale({ 50, 50 });
	addComponent(new SpriteComponet("Sprite/Larrot.png"));//This makes all enmey into the larrot

	//adds the Roming componet
	RomingComponet* romingComp = new RomingComponet(100, 200, 300);
	addComponent(romingComp);

	//adds the seekComponet
	SeekComponet* seekingComp = new SeekComponet();
	seekingComp->setSteeringForce(200);
	seekingComp->setTarget(m_targetActor);
	addComponent(seekingComp);
}

void Enemy::update(float deltaTime)
{
	Agent::update(deltaTime);
}
