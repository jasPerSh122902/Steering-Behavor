#include "MainScene.h"
#include "Transform2D.h"
#include "Player.h"
#include "Enemy.h"

void MainScene::start()
{
	Player* player = new Player(250, 300, "Player", 500, 10);
	player->getTransform()->setScale({ 150,150 });
	addActor(player);

	/*Agent* agent = new Agent(400, 300, "agent1", player);
	agent->getTransform()->setScale({ 200, 200 });
	addActor(agent);*/

	Enemy* enemy = new Enemy(400, 300, "Enemy",100, 10, player);
	enemy->getTransform()->setScale({ 100,100 });
	addActor(enemy);
}
