#include "RomingDecision.h"
#include "RomingComponet.h"
#include "Agent.h"
#include "SeekComponet.h"
void RomingDecision::makeDecision(Agent* actor, float deltaTime)
{
	RomingComponet* roming = actor->getComponent<RomingComponet>();
	SeekComponet* seek = actor->getComponent<SeekComponet>();

	if (roming)
		roming->setSteeringForce(104);

	if (seek)
		seek->setSteeringForce(0);
}
