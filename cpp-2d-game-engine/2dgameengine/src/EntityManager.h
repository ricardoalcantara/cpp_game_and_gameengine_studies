#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Entity.h"
#include "Component.h"

class EntityManager
{
private:
    std::vector<Entity *> entities;

public:
    void ClearData();
    void Update(float delta);
    void Render(sf::RenderWindow &window);
    bool HasEntities();
    Entity &AddEntity(std::string entityName);
    std::vector<Entity *> GetEntities() const;
    size_t GetEntityCount();
};
#endif