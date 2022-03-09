#pragma once
#include "Componet.h"

enum State
{
	IDLE,
	SEEKING,
	Roming
};

class SeekComponet;
class RomingComponet;

class StateMachineComponet :
	public Componet
{
public:
	void start() override;
	State getCurrentState() { return m_currentState; }
	void setCurrentState(State state) { m_currentState = state; }
	void update(float deltaTime) override;

private:
	State m_currentState;
	SeekComponet* m_seekComponet;
	RomingComponet* m_romingComponet;
	float m_seekForce;
	float m_romingForce;
	float m_seekRange = 150;
};

