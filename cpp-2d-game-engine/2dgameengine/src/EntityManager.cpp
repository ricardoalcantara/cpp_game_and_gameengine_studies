#include "EntityManager.h"
#include <iostream>

void EntityManager::ClearData()
{
    for (auto &entity : entities)
    {
        entity->Destroy();
    }
}

void EntityManager::Update(float delta)
{
    for (auto &entity : entities)
    {
        entity->Update(delta);
    }
}

void EntityManager::Render(sf::RenderWindow &window)
{
    for (auto &entity : entities)
    {
        entity->Render(window);
    }
}

bool EntityManager::HasEntities()
{
    return entities.size() > 0;
}

Entity &EntityManager::AddEntity(std::string entityName)
{
    std::cout << "Entity created: " << entityName << std::endl;
    Entity *entity = new Entity(*this, entityName);
    entities.emplace_back(entity);
    return *entity;
}

std::vector<Entity *> EntityManager::GetEntities() const
{
    return entities;
}

size_t EntityManager::GetEntityCount()
{
    return entities.size();
}
