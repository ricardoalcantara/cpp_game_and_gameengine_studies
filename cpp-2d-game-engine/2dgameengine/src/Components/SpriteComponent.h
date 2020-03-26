#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Component.h"
#include "Game.h"
#include "Animation.h"

class SpriteComponent : public Component
{
private:
    TransformComponent *transform = nullptr;
    sf::Texture *texture;
    sf::Sprite *sprite;
    sf::Vector2f position;
    sf::IntRect rect;

    bool isAnimated;
    int numFrames;
    float animationSpeed;
    float currentFrameTime = 0;
    int currentFrame = 0;
    bool isFixed;
    std::map<std::string, Animation> animations;
    std::string currentAnimationName;
    unsigned int animationIndex = 0;

public:
    SpriteComponent(const char *filePath)
    {
        isAnimated = false;
        isFixed = false;
        SetTexture(filePath);
    }

    SpriteComponent(const char *filePath, int numFrames, float animationSpeed, bool hasDirections, bool isFixed)
    {
        this->isAnimated = true;
        this->numFrames = numFrames;
        this->animationSpeed = animationSpeed;
        this->isFixed = isFixed;
        if (hasDirections)
        {
            Animation downAnimation = Animation(0, numFrames, animationSpeed);
            Animation rightAnimation = Animation(1, numFrames, animationSpeed);
            Animation leftAnimation = Animation(2, numFrames, animationSpeed);
            Animation upAnimation = Animation(3, numFrames, animationSpeed);
            animations.emplace("DownAnimation", downAnimation);
            animations.emplace("RightAnimation", rightAnimation);
            animations.emplace("LeftAnimation", leftAnimation);
            animations.emplace("UpAnimation", upAnimation);

            this->animationIndex = 0;
            this->currentAnimationName = "DownAnimation";
        }
        else
        {
            Animation singleAnimation = Animation(0, numFrames, animationSpeed);
            animations.emplace("SingleAnimation", singleAnimation);
            this->animationIndex = 0;
            this->currentAnimationName = "SingleAnimation";
        }

        Play(this->currentAnimationName);
        SetTexture(filePath);
    }

    void Play(std::string animationName)
    {
        numFrames = animations[animationName].numFrames;
        animationIndex = animations[animationName].index;
        animationSpeed = animations[animationName].animationSpeed;
        currentAnimationName = animationName;
    }

    void SetTexture(std::string assetTextureId)
    {
        std::cout << assetTextureId << std::endl;
        texture = Game::assetManager->GetTexture(assetTextureId);
        sprite = new sf::Sprite(*texture);
    }

    virtual void Initialize() override
    {
        if (owner->HasComponent<TransformComponent>())
        {
            transform = owner->GetComponent<TransformComponent>();
            rect.width = static_cast<int>(transform->width);
            rect.height = static_cast<int>(transform->height);
        }
    }

    virtual void Update(float delta) override
    {
        if (transform == nullptr)
            return;

        currentFrameTime += delta;

        if (currentFrameTime >= animationSpeed)
        {
            currentFrameTime = 0.0;
            currentFrame = (currentFrame + 1) % numFrames;
        }

        if (isAnimated)
        {
            rect.left = rect.width * currentFrame;
        }

        rect.top = animationIndex * rect.height;

        sprite->setTextureRect(rect);
        sprite->setPosition(transform->position);
    }

    virtual void Render(sf::RenderWindow &window) override
    {
        window.draw(*sprite);
    }
};
#endif