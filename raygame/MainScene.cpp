#include "MainScene.h"
#include "Transform2D.h"
#include "Player.h"
#include "Agent.h"
#include "SpriteComponet.h"
#include "SeekComponet.h"
#include "MovementComponet.h"
#include "RomingComponet.h"

void MainScene::start()
{
	Player* player = new Player(250, 300, "Player", 250, 10);//used the contructor of the plaeyr and put in values
	player->getTransform()->setScale({ 70,70 });//set how big the player will be on the x and y
	MovementComponet* playerMove = player->addComponent<MovementComponet>();

	Agent* agent = new Agent();
	agent->getTransform()->setScale({ 50, 50 });
	agent->setMaxForce(44);
	agent->addComponent(new SpriteComponet("Sprite/Larrot.png"));//This makes all enmey and players into the larrot
	RomingComponet* romingcomp = new RomingComponet(10, 20, 50);
	//SeekComponet* comp = new SeekComponet();
	//comp->setTarget(player);
	agent->addComponent(romingcomp);
	//agent->addComponent(comp);

	//agent added 
	addActor(agent);
	addActor(player);//added that plaeyr to the scene
}
