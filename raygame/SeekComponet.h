#pragma once
#include "SteeringComponet.h"
class SeekComponet :
	public SteeringComponet
{
public:
	MathLibrary::Vector2 calculateForce() override;
	
};

