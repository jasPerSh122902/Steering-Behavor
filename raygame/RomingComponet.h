#pragma once
#include "Componet.h"
class RomingComponet :
    public Componet
{
public:
    RomingComponet();
    ~RomingComponet();
    void update(float deltaTime) override;
    //add a on collision
    Actor* getOwner() { return m_owner; }//returns a owner
    void setOwner(Actor* owner) { m_owner = owner; }//sets the owner
private:
    float m_radius;
    Actor* m_owner;
};

