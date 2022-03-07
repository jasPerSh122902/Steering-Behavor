#include "MovementComponet.h"
#include "Actor.h"
#include "Transform2D.h"
#include "Componet.h"

MovementComponet::MovementComponet(Actor* actor) 
{
	m_maxSpeed = 100;

}

void MovementComponet::update(float deltaTime)
{
	if (m_velocity.getMagnitude() > m_maxSpeed){//the magnitude is greater than the max speed meanign that it is over the max speed
		m_velocity = m_velocity.getNormalized() * m_maxSpeed;//set the velocity to the velocity but normalized and mulitiplied by the max speed
	}
		//add the new vbelocity to the old position to get the new position
		MathLibrary::Vector2 currentPosition = getOwner()->getTransform()->getLocalPosition();
		//makes a forward that is the owners forward
		MathLibrary::Vector2 forward = getOwner()->getTransform()->getForward();
		//changed the x and the y and allows for movement
		MathLibrary::Vector2 newPosition = MathLibrary::Vector2((currentPosition.x + (m_velocity.x * deltaTime)),
																 currentPosition.y + (m_velocity.y * deltaTime));

		//set the actors position to be the new position found
		if (newPosition.getMagnitude() > 0)//if the positiions magnitude is greater than 0
			getOwner()->getTransform()->setLocalPosition(newPosition);//gets the owners local and set it to the new position.
	
}
