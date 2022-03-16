#include "AggressiveDecision.h"
#include "Enemy.h"

bool AggressiveDecision::checkCondition(Agent* actor, float deltaTime)
{
	Enemy* enemy = dynamic_cast<Enemy*>(actor);

	if (enemy)
		return enemy->getIsAgressive();

	return false;
}
