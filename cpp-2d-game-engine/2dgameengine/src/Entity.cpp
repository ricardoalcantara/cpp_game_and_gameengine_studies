#include "Entity.h"

Entity::Entity(EntityManager &manager) : manager(manager)
{
    isActive = true;
}

Entity::Entity(EntityManager &manager, std::string name, LayerType layer) : manager(manager), name(name), layer(layer)
{
    isActive = true;
}

void Entity::Update(float delta)
{
    for (auto &component : components)
    {
        component->Update(delta);
    }
}

void Entity::Render(sf::RenderWindow &window)
{
    for (auto &component : components)
    {
        component->Render(window);
    }
}

void Entity::Destroy()
{
    isActive = false;
}

bool Entity::IsActive() const
{
    return isActive;
}