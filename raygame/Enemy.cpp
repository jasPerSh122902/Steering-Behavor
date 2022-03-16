#include "Enemy.h"
#include "SeekComponet.h"
#include "RomingComponet.h"
#include "SpriteComponet.h"
#include "Transform2D.h"
//decision
#include "DecisionComponent.h"
#include "AggressiveDecision.h"
#include "IdleDecision.h"
#include "RomingDecision.h"
#include "inRangeDecisions.h"
#include "SeekDecision.h"

Enemy::Enemy(float x, float y, const char* name, float maxSpeed, float maxForce, Actor* targetActor)
	: Agent(x , y , name , maxSpeed , maxForce)
{
	m_targetActor = targetActor;
}

void Enemy::start()
{
	Agent::start();

	IdleDecision* idle = new IdleDecision();
	RomingDecision* roming = new RomingDecision();
	SeekDecision* seek = new SeekDecision();

	AggressiveDecision* aggressive = new AggressiveDecision(idle, roming);
	inRangeDecisions* inRange = new inRangeDecisions(aggressive, seek);

	addComponent(new DecisionComponent(inRange));

	//adds spriteComponent
	getTransform()->setScale({ 50, 50 });
	addComponent(new SpriteComponet("Sprite/Larrot.png"));//This makes all enmey into the larrot

	//adds the Roming componet
	RomingComponet* romingComp = new RomingComponet(200, 200, 150);
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

bool Enemy::getTargetInRange()
{
	float distance = (m_targetActor->getTransform()->getWorldPosition() - getTransform()->getWorldPosition()).getMagnitude();
	return distance <= 222;
}
