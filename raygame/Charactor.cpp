#include "Charactor.h"
#include "MovementComponet.h"
#include "SpriteComponet.h"
//#include "HealthComp.h"

Character::Character(float x, float y, const char* name, float speed, int maxHealth) :
	Actor::Actor(x, y, name)
{
	m_speed = speed;
	m_firingCooldown = 0.6f;
	m_maxHealth = maxHealth;
}

Character::~Character()
{
}

/// <summary>
/// Adds all of the character's components to its components array
/// </summary>
void Character::start()
{
	m_moveComponet = addComponent<MovementComponet>();
	SpriteComponet* spriteComponent = new SpriteComponet("Sprite/Larrot.png");//This makes all enmey and players into the larrot
	addComponent(spriteComponent);

	Actor::start();
}

/// <summary>
/// Called every frame
/// </summary>
/// <param name="deltaTime">The amount of time that has passed between frames</param>
void Character::update(float deltaTime)
{
	Actor::update(deltaTime);
}

/// <summary>
/// Called every frame
/// </summary>
void Character::draw()
{
	Actor::draw();
}
