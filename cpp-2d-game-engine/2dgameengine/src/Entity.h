#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Component.h"

class EntityManager;

class Entity
{
private:
    EntityManager &manager;
    bool isActive;
    std::vector<Component *> components;

public:
    std::string name;

public:
    Entity(EntityManager &manager);
    Entity(EntityManager &manager, std::string name);
    void Initialize();
    void Update(float delta);
    void Render(sf::RenderWindow &window);
    void Destroy();
    bool IsActive() const;

    template <typename T, typename... TArgs>
    T &AddComponent(TArgs &&... args)
    {
        T *component(new T(std::forward<TArgs>(args)...));
        component->owner = this;
        components.emplace_back(component);
        component->Initialize();

        return *component;
    }
};
#endif