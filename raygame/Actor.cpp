#include "Actor.h"
#include "Transform2D.h"
#include <string.h>
#include "Collider.h"
#include "Componet.h"

Actor::Actor()
{
    m_transform = new Transform2D(this);
}

Actor::~Actor()
{
    delete m_transform;
}

Actor::Actor(float x, float y, const char* name = "Actor")
{
    //Initialze default values
    m_transform = new Transform2D(this);
    m_transform->setLocalPosition({ x,y });
    m_name = name;
}

void Actor::start()
{
    m_started = true;
}

Componet* Actor::addComponent(Componet* actor_componet)
{
    //returns null if this componet has an owner already
    Actor* owner = actor_componet->getOwner();
    if (owner)
        return nullptr;

    actor_componet->assignOwner(this);

    //Create a new array with a size one greater than our old array
    Componet** tempArray = new Componet * [m_componetsCount + 1];
    //Copy the values form the old array to the new array
    for (int i = 0; i < m_componetsCount; i++)
    {
        tempArray[i] = m_componet[i];
    }

    //Set the last value in the new array
    tempArray[m_componetsCount] = actor_componet;
    if (m_componetsCount > 1)
        delete[] m_componet;

    else if (m_componetsCount == 1)
        delete m_componet;
    m_componet = tempArray;
    //increments the counter
    m_componetsCount++;
    //returns the pointer
    return actor_componet;
}

Componet* Actor::getComponent(const char* componetName)
{
    //Iterates through the componet array...
    for (int i = 0; i < m_componetsCount; i++)
    {
        //Return the componetnt if the name is the same as the current componet
        if (strcmp(m_componet[i]->getName(), componetName) == 0)
            return m_componet[i];
    }
    //returns nullprtr if the componet is not in the list
    return nullptr;
}

bool Actor::removeComponent(Componet* componet)
{
    if (!componet)
        return false;

    bool componentRemoved = false;
    //Create a new array with a size one less than our old array
    Componet** newArray = new Componet * [m_componetsCount - 1];

    //Create variable to access tempArray index
    int j = 0;
    //Copy values from the old array to the new array
    for (int i = 0; i < m_componetsCount; i++)
    {
        if (componet != m_componet[i])
        {
            newArray[j] = m_componet[i];
            j++;
        }
        else
            componentRemoved = true;
    }
    //checks to see if The removed is true...
    if (componentRemoved)
    {
        delete[] m_componet;
        //...sets the old array to the new array
        m_componet = newArray;
        m_componetsCount--;//decrements the counter.
        //deletes the componet
        delete(componet);
    }
    delete[] newArray;
    //Return whether or not the removal was successful
    return componentRemoved;
}

bool Actor::removeComponent(const char* name)
{
    if (!name)
        return false;

    bool componentRemoved = false;
    //Create a new array with a size one less than our old array
    Componet* componetoDelete = nullptr;

    Componet** newArray = new Componet * [m_componetsCount - 1];

    //Create variable to access tempArray index
    int j = 0;
    //Copy values from the old array to the new array
    for (int i = 0; i < m_componetsCount; i++)
    {
        //checks to see if the name of the componet and the name is equal
        if (strcmp(m_componet[i]->getName(), name) == 0)
        {
            //makes the new array equal to the old array
            newArray[j] = m_componet[i];
            //increment j
            j++;
        }
        else
        {
            componentRemoved = true;
            componetoDelete = m_componet[i];
        }

    }
    //checks to see if The removed is true...
    if (componentRemoved)
    {
        delete[] m_componet;
        //...sets the old array to the new array
        m_componet = newArray;
        m_componetsCount--;//decrements the counter.
        //deletes the componet
        delete componetoDelete;
    }
    else
        delete[] newArray;
    //Return whether or not the removal was successful
    return componentRemoved;
}

void Actor::update(float deltaTime)
{
    for (int i = 0; i < m_componetsCount; i++)
    {
        if (m_componet[i]->getStarted())
            m_componet[i]->start();

        m_componet[i]->update(deltaTime);
    }
}

void Actor::draw()
{
    for (int i = 0; i < m_componetsCount; i++)
        m_componet[i]->draw();
}

void Actor::end()
{
    m_started = false;

    for (int i = 0; i < m_componetsCount; i++)
        m_componet[i]->end();
}

void Actor::onCollision(Actor* other)
{
    for (int i = 0; i < m_componetsCount; i++)
        m_componet[i]->oncollison(other);
}

void Actor::onDestroy()
{
    for (int i = 0; i < m_componetsCount; i++)
        m_componet[i]->onDistroy();
    //Removes this actor from its parent if it has one
    if (getTransform()->getParent())
        getTransform()->getParent()->removeChild(getTransform());
}

bool Actor::checkForCollision(Actor* other)
{
    //Call check collision if there is a collider attached to this actor
    if (m_collider)
        return m_collider->checkCollision(other);

    return false;
}