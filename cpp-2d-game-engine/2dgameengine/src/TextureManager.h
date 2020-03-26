#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SFML/Graphics.hpp>

class TextureManager
{
public:
    static sf::Texture *LoadTexture(const char *fileName)
    {
        sf::Texture *texture = new sf::Texture;
        texture->loadFromFile(fileName);
        return texture;
    }
};
#endif