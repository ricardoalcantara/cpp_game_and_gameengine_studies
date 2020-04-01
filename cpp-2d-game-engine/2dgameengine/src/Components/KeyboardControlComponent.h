#ifndef KEYBOARDCONTROLCOMPONENT_H
#define KEYBOARDCONTROLCOMPONENT_H

#include <SFML/Graphics.hpp>
#include <cmath>

#include "Component.h"
#include "Components/TransformComponent.h"
#include "Components/SpriteComponent.h"

class KeyboardControlComponent : public Component
{
public:
    std::string upKey;
    std::string downKey;
    std::string leftKey;
    std::string rightKey;
    std::string shootKey;
    TransformComponent *transform;
    SpriteComponent *sprite;

public:
    KeyboardControlComponent()
    {
    }

    KeyboardControlComponent(std::string upKey,
                             std::string downKey,
                             std::string leftKey,
                             std::string rightKey,
                             std::string shootKey)
    {
        this->upKey = upKey;
        this->downKey = downKey;
        this->leftKey = leftKey;
        this->rightKey = rightKey;
        this->shootKey = shootKey;
    }

    void Initialize()
    {
        transform = owner->GetComponent<TransformComponent>();
        sprite = owner->GetComponent<SpriteComponent>();
    }

    void Update(float)
    {
        transform->velocity.x = 0;
        transform->velocity.y = 0;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            transform->velocity.y -= 1;
            sprite->Play("UpAnimation");
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            transform->velocity.y += 1;
            sprite->Play("DownAnimation");
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            transform->velocity.x -= 1;
            sprite->Play("LeftAnimation");
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            transform->velocity.x += 1;
            sprite->Play("RightAnimation");
        }

        float length = sqrt((transform->velocity.x * transform->velocity.x) + (transform->velocity.y * transform->velocity.y));
        if (length != 0)
        {
            transform->velocity.x = transform->velocity.x / length;
            transform->velocity.y = transform->velocity.y / length;
        }
    }

    void Render(sf::RenderWindow &) {}
};
#endif