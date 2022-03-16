#include "MainScene.h"
#include "Transform2D.h"
#include "Player.h"
#include "Agent.h"
#include "SpriteComponet.h"
#include "Enemy.h"

void MainScene::start()
{
	Player* player = new Player(250, 300, "Player", 250, 10);//used the contructor of the plaeyr and put in values
	player->getTransform()->setScale({ 70,70 });//set how big the player will be on the x and y

	//Agent* agent = new Agent(200,200,"Agent", 150,150);
	
	Enemy* enemy = new Enemy(150,150, "Enemey", 150, 150, player);

	addActor(enemy);
	addActor(player);
	//addActor(agent);
}
