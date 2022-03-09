#include "MainScene.h"
#include "Transform2D.h"
#include "Player.h"
#include "Enemy.h"
#include "Agent.h"
#include "SpriteComponet.h"
#include "SeekComponet.h"
#include "MovementComponet.h"

void MainScene::start()
{
	Player* player = new Player(250, 300, "Player", 500, 10);//used the contructor of the plaeyr and put in values
	player->getTransform()->setScale({ 150,150 });//set how big the player will be on the x and y
	MovementComponet* playerMove = player->addComponent<MovementComponet>();


	Agent* agent = new Agent();
	agent->getTransform()->setScale({ 50, 50 });
	agent->setMaxForce(44);
	agent->addComponent( new SpriteComponet("Sprite/Larrot.png"));//This makes all enmey and players into the larrot
	SeekComponet* comp = new SeekComponet();
	comp->setTarget(player);
	agent->addComponent(comp);
	
	addActor(player);//added that plaeyr to the scene
	addActor(agent);

}
