#include "AssetManager.h"
#include "TextureManager.h"

AssetManager::AssetManager(EntityManager *manager) : manager(manager)
{
}

AssetManager::~AssetManager()
{
}

void AssetManager::CleanData()
{
    textures.clear();
}

void AssetManager::AddTexture(std::string textureId, const char *filePath)
{
    textures.emplace(textureId, TextureManager::LoadTexture(filePath));
}

sf::Texture *AssetManager::GetTexture(std::string textureId)
{
    return textures[textureId];
}
