#ifndef CAMERACOMPONENT_H
#define CAMERACOMPONENT_H

#include <SFML/Graphics.hpp>
#include "EntityManager.h"
#include "Components/ScreenLimiterComponent.h"
#include "Components/TransformComponent.h"
#include "Constants.h"
#include "Math/Math.h"

class CameraComponent : public Component
{
public:
    sf::View camera;
    sf::Vector2f position;
    sf::FloatRect rect;
    TransformComponent *transform = nullptr;
    ScreenLimiterComponent *screenLimiter = nullptr;

public:
    CameraComponent()
    {
    }

    void Initialize() override
    {
        transform = owner->GetComponent<TransformComponent>();
        if (owner->HasComponent<ScreenLimiterComponent>())
        {
            screenLimiter = owner->GetComponent<ScreenLimiterComponent>();
            rect.top = screenLimiter->rect.top + (WINDOW_HEIGHT / 2);
            rect.left = screenLimiter->rect.left + (WINDOW_WIDTH / 2);
            rect.width = screenLimiter->rect.width - (WINDOW_WIDTH / 2);
            rect.height = screenLimiter->rect.height - (WINDOW_HEIGHT / 2);
        }
    }

    void Update(float) override
    {
        if (transform == nullptr)
            return;

        position.x = transform->position.x;
        position.y = transform->position.y;

        if (screenLimiter != nullptr)
        {
            position.x = clamp(position.x, rect.left, rect.width);
            position.y = clamp(position.y, rect.top, rect.height);
        }
        }

    void Render(sf::RenderWindow &window) override
    {
        camera = window.getView();
        camera.setCenter(position);
        window.setView(camera);
    }
};
#endif