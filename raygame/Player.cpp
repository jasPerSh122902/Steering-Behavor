#include "Player.h"
#include "InputComponet.h"
#include "MovementComponet.h"
#include "Transform2D.h"

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
	//checks to see if the magnitude on the move axis is greater than 0
	if (m_inputComponet->getMoveAxis().getMagnitude() > 0)
		getTransform()->setForward(m_inputComponet->getMoveAxis());// allows the player to look were you are going to move
	//allows for movement
	Character::getTheMoveComponet()->setVelocity(m_inputComponet->getMoveAxis() * Character::getSpeed());
	Character::update(deltaTime);
}
