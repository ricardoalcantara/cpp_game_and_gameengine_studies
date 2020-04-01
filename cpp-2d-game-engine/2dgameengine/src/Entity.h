#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <map>
#include <string>
#include "Component.h"
#include "Constants.h"

class EntityManager;

class Entity
{
private:
    EntityManager &manager;
    bool isActive;
    std::vector<Component *> components;
    std::map<const std::type_info *, Component *> componentsTypeMap;

public:
    std::string name;
    LayerType layer;

public:
    Entity(EntityManager &manager);
    Entity(EntityManager &manager, std::string name, LayerType layer);
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
        componentsTypeMap[&typeid(*component)] = component;
        return *component;
    }

    template <typename T>
    T *GetComponent()
    {
        return static_cast<T *>(componentsTypeMap[&typeid(T)]);
    }

    template <typename T>
    bool HasComponent()
    {
        return componentsTypeMap.find(&typeid(T)) != componentsTypeMap.end();
    }
};
#endif