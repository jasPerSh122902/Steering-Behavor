#include "Player.h"
#include "InputComponet.h"
#include "MovementComponet.h"
#include "SpriteComponet.h"

Player::Player(float x, float y, const char* name, float speed, int maxHealth) :
	Character(x, y, name, speed, maxHealth)
{}

void Player::start()
{
	Character::start();

	m_inputComponet = dynamic_cast<InputComponet*>(addComponent(new InputComponet()));
}

void Player::update(float deltaTime)
{
	//allows for movement
	Character::getTheMoveComponet()->setVelocity(m_inputComponet->getMoveAxis() * Character::getSpeed());
	//this will break the retreat and seek
	//m_movementComponet->setVelocity(m_inputComponet->getMoveAxis());
	Character::update(deltaTime);
}
