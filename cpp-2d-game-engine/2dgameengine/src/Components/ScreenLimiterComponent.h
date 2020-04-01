#ifndef SCREENLIMITERCOMPONENT_H
#define SCREENLIMITERCOMPONENT_H

#include <SFML/Graphics.hpp>
#include "Components/TransformComponent.h"
#include "Math/Math.h"

class ScreenLimiterComponent : public Component
{
public:
    sf::FloatRect rect;
    TransformComponent *transform = nullptr;
    SpriteComponent *sprite = nullptr;

public:
    ScreenLimiterComponent(float x, float y, float w, float h)
    {
        rect.top = y;
        rect.left = x;
        rect.width = w;
        rect.height = h;
    }

    void Initialize() override
    {
        transform = owner->GetComponent<TransformComponent>();
        sprite = owner->GetComponent<SpriteComponent>();
    }

    void Update(float) override
    {
        transform->position.x = clamp(transform->position.x, rect.left, rect.width - sprite->rect.width);
        transform->position.y = clamp(transform->position.y, rect.top, rect.height - sprite->rect.height);
    }
};
#endif