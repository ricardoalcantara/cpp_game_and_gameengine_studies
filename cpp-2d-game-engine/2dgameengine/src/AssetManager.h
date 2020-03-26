#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include <map>
#include <string>
#include <SFML/Graphics.hpp>

class EntityManager;

class AssetManager
{
private:
    EntityManager *manager;
    std::map<std::string, sf::Texture *> textures;

public:
    AssetManager(EntityManager *manager);
    ~AssetManager();
    void CleanData();
    void AddTexture(std::string textureId, const char *filePath);
    sf::Texture *GetTexture(std::string textureId);
};
#endif