#pragma once
#include "Actor.h"
class Input;
class Movement;
class Sprite;

class Player :
    public Actor
{
public:

    /// <param name="x">Position on the x axis</param>
    /// <param name="y">Position on the y axis</param>
    /// <param name="name">The name of this actor.</param>
    //Player(float x, float y, int health, float speed, int maxHealth);

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
