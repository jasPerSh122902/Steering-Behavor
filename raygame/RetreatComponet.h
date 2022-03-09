#pragma once
#include "SteeringComponet.h"
class RetreatComponet :
    public SteeringComponet
{

public:
	
	MathLibrary::Vector2 calculateForce() override;
};

