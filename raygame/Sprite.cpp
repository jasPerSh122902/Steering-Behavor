#include "Sprite.h"
#include "Actor.h"
#include "Transform2D.h"
#include <raylib.h>
#include <Matrix3.h>
#include <cmath>

Sprite::Sprite(Texture2D* texture, const char* name)
{
	texture = m_texture;
}

Sprite::Sprite(const char* path, const char* name) : Componet::Componet(name)
{
	m_texture = new Texture2D(RAYLIB_H::LoadTexture(path));
}

Sprite::~Sprite()
{
	RAYLIB_H::UnloadTexture(*m_texture);
	delete(m_texture);
}

void Sprite::draw()
{
	//Gets the Scale of the global matrix
	m_width = getOwner()->getTransform()->getScale().x;
	m_height = getOwner()->getTransform()->getScale().y;

	m_texture->width = m_width;
	m_texture->height = m_height;

	//gets the world POSISTION of the owner
	//top is x and the bottom is y
	//makes the up with the transform of xy, and the yy
	MathLibrary::Vector2 up = { getOwner()->getTransform()->getGlobalMatrix()->m01,
								getOwner()->getTransform()->getGlobalMatrix()->m11 };
	//gets the forward of the actor
	MathLibrary::Vector2 forward = getOwner()->getTransform()->getForward();
	//gets the position of the actor
	MathLibrary::Vector2 position = getOwner()->getTransform()->getWorldPosition();

	//Change the position of the sprite to e in the center of the transform
	//sets the position to the forawd...
	position = position - (forward * getWidth() / 2);
	//sets the position to the up...
	position = position - (up.getNormalized() * getHight() / 2);

	//Creates a Raylib posistion using vector2
	RAYLIB_H::Vector2 rayPos = { position.x, position.y };

	//gets the ROTATSHION of the owner transform
	float rotation = atan2(getOwner()->getTransform()->getGlobalMatrix()->m10, getOwner()->getTransform()->getGlobalMatrix()->m00);

	//DRAW THE SPRITE
	RAYLIB_H::DrawTextureEx(*m_texture, rayPos, (float)(rotation * 180.0f / PI), 1, BLUE);
}