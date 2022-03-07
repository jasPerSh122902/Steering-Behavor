#include "MainScene.h"
#include "Transform2D.h"
#include "Player.h"
#include "Enemy.h"

void MainScene::start()
{
	Player* player = new Player(250, 300, "Player", 500, 10);//used the contructor of the plaeyr and put in values
	player->getTransform()->setScale({ 150,150 });//set how big the player will be on the x and y
	addActor(player);//added that plaeyr to the scene

	/*Agent* agent = new Agent(400, 300, "agent1", player);
	agent->getTransform()->setScale({ 200, 200 });
	addActor(agent);*/

	Enemy* enemy = new Enemy(400, 300, "Enemy", 600, 10, player);//used the contructor of the plaeyr and put in the values
	enemy->getTransform()->setScale({ 100,100 });//set how big the enemy will be on the x and y
	addActor(enemy);//added the enemy to the scene
}
