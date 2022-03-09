#include "MainScene.h"
#include "Transform2D.h"
#include "Player.h"
#include "Agent.h"
#include "SpriteComponet.h"
#include "SeekComponet.h"
#include "MovementComponet.h"
#include "RomingComponet.h"
#include "StateMachineComponet.h"

void MainScene::start()
{
	Player* player = new Player(250, 300, "Player", 250, 10);//used the contructor of the plaeyr and put in values
	player->getTransform()->setScale({ 70,70 });//set how big the player will be on the x and y
	MovementComponet* playerMove = player->addComponent<MovementComponet>();

	//for (size_t i = 0; i < 10; i++)
	//{
		Agent* agent = new Agent();
		agent->getTransform()->setScale({ 50, 50 });
		agent->setMaxForce(500);
		agent->addComponent(new SpriteComponet("Sprite/Larrot.png"));//This makes all enmey and players into the larrot

		RomingComponet* romingComp = new RomingComponet(100, 200, 300);
		agent->addComponent(romingComp);

		SeekComponet* seekingComp = new SeekComponet();
		seekingComp->setSteeringForce(200);
		seekingComp->setTarget(player);

		agent->addComponent(seekingComp);
		agent->addComponent<StateMachineComponet>();
		addActor(agent);
	//}
	

	//agent added 
	addActor(player);
	


	
}
