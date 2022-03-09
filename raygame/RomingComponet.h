#pragma once
#include "Componet.h"
#include "SteeringComponet.h"
class RomingComponet :
    public SteeringComponet
{
public:
    RomingComponet(float circleDistance, float circleRadius, float wanderForce);
    MathLibrary::Vector2 calculateForce() override;
    float getTheRand();
private:
    float m_radius = 0;
    float m_distance = 0;
    float m_wanderAngle = 0;//we will come back to this
    MathLibrary::Vector2 m_target;
    MathLibrary::Vector2 m_circlePos;
};

