#include "inRangeDecisions.h"
#include "Enemy.h"

bool inRangeDecisions::checkCondition(Agent* actor, float deltaTime)
{
	Enemy* enemy = dynamic_cast<Enemy*>(actor);
	
	if (enemy)
		return enemy->getTargetInRange();

	return false;
}
