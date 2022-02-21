#include "MainScene.h"
#include "Sprite.h"
#include "Movement.h"
#include "Transform2D.h"
#include "Input.h"
#include "Player.h"
#include "Enemy.h"
#include "Agent.h"

void MainScene::start()
{
	Player* player = new Player(250, 300, "Player");
	player->getTransform()->setScale({ 150,150 });
	addActor(player);

	Agent* agent = new Agent(400, 300, "agent1", player);
	agent->getTransform()->setScale({ 200, 200 });
	addActor(agent);

	/*Enemy* enemy = new Enemy(400, 300, "Player", player);
	enemy->getTransform()->setScale({ 100,100 });
	addActor(enemy);*/
}
