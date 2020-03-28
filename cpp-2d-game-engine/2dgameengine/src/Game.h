#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "EntityManager.h"

class AssetManager;

class Game
{
private:
    bool isRunning;
    sf::RenderWindow *window = nullptr;
    sf::Clock clock;
    EntityManager manager;
    float fps = 0;
    float fpsDelta = 0;
    bool lockFps = false;
    bool showFps = true;

private:
    void ShowFPS(float delta);

public:
    static AssetManager *assetManager;
    const char *WINDOW_GAME_TITLE = "2D Game Engine";

public:
    Game();
    ~Game();
    bool IsRunning() const;
    void Initialize(int width, int height);
    void ProcessInput();
    void Update();
    void Render();
    void Destroy();
    void LoadLevel(int levelNumber);
};

#endif