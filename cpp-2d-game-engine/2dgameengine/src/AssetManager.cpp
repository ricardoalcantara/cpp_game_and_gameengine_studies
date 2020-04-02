#include "AssetManager.h"

AssetManager::AssetManager(EntityManager *manager) : manager(manager)
{
}

AssetManager::~AssetManager()
{
}

void AssetManager::CleanData()
{
    textures.clear();
    fonts.clear();
}

void AssetManager::AddTexture(std::string textureId, const char *filePath)
{
    sf::Texture *texture = new sf::Texture;
    texture->loadFromFile(filePath);
    textures.emplace(textureId, texture);
}

sf::Texture *AssetManager::GetTexture(std::string textureId)
{
    return textures[textureId];
}

void AssetManager::AddFont(std::string fontId, const char *filePath)
{
    sf::Font *font = new sf::Font;
    font->loadFromFile(filePath);
    fonts.emplace(fontId, font);
}

sf::Font *AssetManager::GetFont(std::string fontId)
{
    return fonts[fontId];
}
