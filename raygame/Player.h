#pragma once
#include "Charactor.h"
class InputComponet;
class MovementComponet;

class Player :
    public Character
{
public:

    Player(float x, float y, const char* name, float speed, int maxHealth);

    ~Player() {}

    /// <summary>
    /// Called during the first update after an actor is added to a scene.
    /// </summary>
    void start() override;
    void update(float deltaTime) override;

private:
    InputComponet* m_inputComponet;
    MovementComponet* m_movementComponet;
};
