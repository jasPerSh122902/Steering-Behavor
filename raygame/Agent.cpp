#include "Agent.h"
#include "Sprite.h"




Agent::Agent(int x, int y, const char* name, Actor* targetActor)
{
	m_targetActor = targetActor;
}

void Agent::start()
{
	Actor::start();
	
	//addComponent(m_seekComponet);
	SeekComponet* m_seekComponet = new SeekComponet("SeekComponet",m_player);
	addComponent(m_seekComponet);
	m_spriteComponet = dynamic_cast<Sprite*>(addComponent(new Sprite("Sprite/Larrot.png")));
}

void Agent::end()
{
}

void Agent::update(float deltaTime)
{
	Actor::update(deltaTime);
}
