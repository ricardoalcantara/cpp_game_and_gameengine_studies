#ifndef TRANSFORMCOMPONENT_H
#define TRANSFORMCOMPONENT_H

#include <SFML/Graphics.hpp>
#include "EntityManager.h"
#include "Component.h"
#include "Constants.h"

class TransformComponent : public Component
{
public:
    sf::Vector2f position;
    sf::Vector2f velocity;
    float speed;
    float width;
    float height;
    float scale;

public:
    TransformComponent(float posX, float posY, float velX, float velY, float spd, float w, float h, float s)
    {
        position = sf::Vector2f(posX, posY);
        velocity = sf::Vector2f(velX, velY);
        speed = spd;
        width = w;
        height = h;
        scale = s;
    }

    virtual void Update(float delta) override
    {
        position += velocity * speed * delta;
    }
};
#endif