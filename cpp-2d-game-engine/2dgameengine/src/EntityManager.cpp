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
    for (unsigned int i = 0; i < NUM_LAYERS; i++)
    {
        LayerType layer = static_cast<LayerType>(i);
        for (auto &entity : GetEntitiesByLayer(layer))
        {
            entity->Render(window);
        }
    }
}

bool EntityManager::HasEntities()
{
    return entities.size() > 0;
}

Entity &EntityManager::AddEntity(std::string entityName, LayerType layer = LayerType::DEFAULT)
{
    std::cout << "Entity created: " << entityName << std::endl;
    Entity *entity = new Entity(*this, entityName, layer);
    entities.emplace_back(entity);
    return *entity;
}

std::vector<Entity *> EntityManager::GetEntities() const
{
    return entities;
}

std::vector<Entity *> EntityManager::GetEntitiesByLayer(LayerType layer) const
{
    std::vector<Entity *> selectedEntities;
    for (auto &entity : entities)
    {
        if (entity->layer == layer)
        {
            selectedEntities.emplace_back(entity);
        }
    }
    return selectedEntities;
}

size_t EntityManager::GetEntityCount()
{
    return entities.size();
}
