#ifndef COMPONENT_H
#define COMPONENT_H

#include <SFML/Graphics.hpp>

class Entity;

class Component
{
public:
    Entity *owner;

public:
    virtual ~Component() {}
    virtual void Initialize() {}
    virtual void Update(float) {}
    virtual void Render(sf::RenderWindow &) {}
};
#endif