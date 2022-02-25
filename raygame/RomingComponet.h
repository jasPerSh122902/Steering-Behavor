#pragma once
#include "Componet.h"
#include "raymath.h"
#include "Transform2D.h"
#include "SteeringComponet.h"
class RomingComponet :
    public SteeringComponet
{
public:
    RomingComponet(Actor* owner,Actor* targetActor, int radius, int orderValue);
    ~RomingComponet();
    void update(float deltaTime) override;
    //add a on collision
    Actor* getOwner() { return m_owner; }//returns a owner
    void setOwner(Actor* owner) { m_owner = owner; }//sets the owner
    Actor* getTarget() { return m_targetActor; }
    int getTheRand();
private:
    int m_radius;
    Actor* m_owner;
    Actor* m_targetActor;
    int m_orderValue;
    MathLibrary::Vector2 m_sterringForce;
    MathLibrary::Vector2 m_desiredVelocity;
    float  m_seekForce = 290;
};

