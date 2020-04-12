#ifndef TILECOMPONENT_H
#define TILECOMPONENT_H

#include <SFML/Graphics.hpp>
#include "Component.h"
#include "Game.h"
#include "AssetManager.h"

class TileComponent : public Component
{
public:
    sf::Texture *texture;
    sf::Sprite *sprite;
    sf::Vector2f position;
    sf::IntRect rect;

public:
    // TileComponent(int, int, int, int, int, int, std::string)
    TileComponent(int sourceRectX, int sourceRectY, int x, int y, int tileSize, int scale, std::string assetTextureId)
    {
        texture = Game::assetManager->GetTexture(assetTextureId);
        sprite = new sf::Sprite(*texture);

        rect.top = sourceRectY;
        rect.left = sourceRectX;
        rect.height = tileSize;
        rect.width = tileSize;
        sprite->setTextureRect(rect);
        sprite->setScale(static_cast<float>(scale), static_cast<float>(scale));

        position.x = static_cast<float>(x);
        position.y = static_cast<float>(y);
        sprite->setPosition(position);
    }

    ~TileComponent()
    {
    }

    void Render(sf::RenderWindow &window) override
    {
        window.draw(*sprite);
    }
};

#endif
