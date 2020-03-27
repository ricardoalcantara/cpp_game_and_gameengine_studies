#ifndef TRANSFORMCOMPONENT_H
#define TRANSFORMCOMPONENT_H

#include <SFML/Graphics.hpp>
#include "EntityManager.h"
#include "Component.h"
#include "Constants.h"

static float F_WINDOW_WIDTH = static_cast<float>(WINDOW_WIDTH);
static float F_WINDOW_HEIGHT = static_cast<float>(WINDOW_HEIGHT);

template <class T>
static float clamp(const T &v, const T &lo, const T &hi)
{
    return (v < lo) ? lo : (hi < v) ? hi : v;
}

class TransformComponent : public Component
{
public:
    sf::Vector2f position;
    sf::Vector2f velocity;
    float speed;
    float width;
    float height;
    float scale;
    // sf::RectangleShape shape;

public:
    TransformComponent(float posX, float posY, float velX, float velY, float spd, float w, float h, float s)
    {
        position = sf::Vector2f(posX, posY);
        velocity = sf::Vector2f(velX, velY);
        speed = spd;
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
        position += velocity * speed * delta;
        position.x = clamp(position.x, 0.0f, F_WINDOW_WIDTH - width);
        position.y = clamp(position.y, 0.0f, F_WINDOW_HEIGHT - height);
        // shape.setPosition(position);
    }

    virtual void Render(sf::RenderWindow &) override
    {
        // window.draw(shape);
    }
};
#endif