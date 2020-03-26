#ifndef TRANSFORMCOMPONENT_H
#define TRANSFORMCOMPONENT_H

#include <SFML/Graphics.hpp>
#include "EntityManager.h"
#include "Component.h"

class TransformComponent : public Component
{
public:
    sf::Vector2f position;
    sf::Vector2f velocity;
    float width;
    float height;
    float scale;
    // sf::RectangleShape shape;

public:
    TransformComponent(float posX, float posY, float velX, float velY, float w, float h, float s)
    {
        position = sf::Vector2f(posX, posY);
        velocity = sf::Vector2f(velX, velY);
        width = w;
        height = h;
        scale = s;

        // shape = sf::RectangleShape(sf::Vector2f(width, height));
        // shape.setFillColor(sf::Color(255, 255, 255, 255));
    }

    virtual void Initialize() override
    {
    }

    virtual void Update(float delta) override
    {
        position += velocity * delta;
        // shape.setPosition(position);
    }

    virtual void Render(sf::RenderWindow &) override
    {
        // window.draw(shape);
    }
};
#endif