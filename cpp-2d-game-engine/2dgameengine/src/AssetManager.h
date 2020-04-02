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
    std::map<std::string, sf::Font *> fonts;

public:
    AssetManager(EntityManager *manager);
    ~AssetManager();
    void CleanData();
    void AddTexture(std::string textureId, const char *filePath);
    void AddFont(std::string fontId, const char *filePath);
    sf::Texture *GetTexture(std::string textureId);
    sf::Font *GetFont(std::string fontId);
};
#endif