#include "Charactor.h"
#include "Movement.h"
#include "Sprite.h"
#include "HealthComp.h"

Character::Character(float x, float y, const char* name, float speed, int maxHealth) :
	Actor::Actor(x, y, name)
{
	m_speed = speed;
	m_firingCooldown = 0.3f;
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
	HealthComp* healthComponent = new HealthComp(m_maxHealth, this);
	addComponent(healthComponent);
	Movement* moveComponent = new Movement("Movement");
	addComponent(moveComponent);
	Sprite* spriteComponent = new Sprite("Sprite/Larrot.png");
	addComponent(spriteComponent);
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
