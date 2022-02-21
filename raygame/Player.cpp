#include "Player.h"
#include "Input.h"
#include "Movement.h"
#include "Sprite.h"

//Player::Player(float x, float y, int health, float speed, int maxHealth)
//{
//}

void Player::start()
{
	Actor::start();

	m_inputComponet = dynamic_cast<Input*>(addComponent(new Input()));
	m_movementComponet = dynamic_cast<Movement*>(addComponent(new Movement()));
	m_movementComponet->setMaxSpeed(500);
	m_spriteComponet = dynamic_cast<Sprite*>(addComponent(new Sprite("Sprite/Learth.png")));


	//Set spawn point here
	//Set move speed
	//Set position clamps
}

void Player::update(float deltaTime)
{
	Actor::update(deltaTime);
	//allows for movement
	MathLibrary::Vector2 moveDirection = m_inputComponet->getMoveAxis();

	m_movementComponet->setVelocity(moveDirection * 300);


}
