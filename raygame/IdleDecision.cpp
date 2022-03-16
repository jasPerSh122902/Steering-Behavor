#include "IdleDecision.h"
#include "SeekComponet.h"
#include "RomingComponet.h"
#include "Agent.h"


void IdleDecision::makeDecision(Agent* actor, float deltaTime)
{
	RomingComponet* roming = actor->getComponent<RomingComponet>();

	if (roming)
		roming->setSteeringForce(0);

	SeekComponet* seek = actor->getComponent<SeekComponet>();

	if (seek)
		seek->setSteeringForce(0);
}
