#include "Componet.h"

Componet::Componet()
{
	m_owner = nullptr;
	m_name = nullptr;
	m_stated = false;
}

Componet::Componet(const char* name)
{
	m_name = name;
}


Componet::~Componet()
{

}

void Componet::assignOwner(Actor* owner)
{
	if (getOwner())//if this returns true then return...
		return;//returns the same owner
	//sets the owner varable to the ower that was put in
	m_owner = owner;
}

void Componet::update(float deltaTime)
{
}

void Componet::draw()
{
}

void Componet::end()
{
}

void Componet::oncollison(Actor* actor)
{
}