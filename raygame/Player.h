#pragma once
#include "Actor.h"
class Input;
class Movement;
class Sprite;

class Player :
    public Actor
{
public:

    Player() {}

    Player(float x, float y, const char* name) : Actor(x, y, name) {}

    /// <summary>
    /// Called during the first update after an actor is added to a scene.
    /// </summary>
    void start() override;
    void update(float deltaTime) override;

private:
    Input* m_inputComponet;
    Movement* m_movementComponet;
    Sprite* m_spriteComponet;
};
