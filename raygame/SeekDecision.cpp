#include "SeekDecision.h"
#include "SeekComponet.h"
#include "RomingComponet.h"
#include "Agent.h"
#include "Enemy.h"
void SeekDecision::makeDecision(Agent* actor, float deltaTime)
{
	SeekComponet* seek = actor->getComponent<SeekComponet>();
	Enemy* enemy = dynamic_cast<Enemy*>(actor);
	RomingComponet* roming = actor->getComponent<RomingComponet>();

	if (roming)
		roming->setSteeringForce(104);

	if (seek)
		seek->setSteeringForce(483);

	if (enemy)
		enemy->setAgressive(true);
}
