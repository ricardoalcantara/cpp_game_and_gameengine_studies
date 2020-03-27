#include <iostream>
#include "Constants.h"
#include "Game.h"
#include "AssetManager.h"

#include "Components/TransformComponent.h"
#include "Components/SpriteComponent.h"
#include "Components/KeyboardControlComponent.h"

static EntityManager manager;
AssetManager *Game::assetManager = new AssetManager(&::manager);

Game::Game()
{
    isRunning = false;
}

Game::~Game()
{
}

bool Game::IsRunning() const
{
    return isRunning;
}

void Game::Initialize(int width, int height)
{
    window = new sf::RenderWindow(sf::VideoMode(width, height), "My window");
    clock.restart();

    if (lockFps)
        window->setFramerateLimit(FPS);
    else
        window->setFramerateLimit(0);

    LoadLevel(0);

    isRunning = true;
}

void Game::LoadLevel(int)
{
    assetManager->AddTexture("tank-image", "assets/images/tank-big-right.png");
    assetManager->AddTexture("chopper-image", "assets/images/chopper-spritesheet.png");
    assetManager->AddTexture("radar-image", "assets/images/radar.png");

    Entity &tankEntity(manager.AddEntity("Tank"));
    tankEntity.AddComponent<TransformComponent>(0.0f, 0.0f, 1.0f, 1.0f, 20.0f, 32.0f, 32.0f, 1.0f);
    tankEntity.AddComponent<SpriteComponent>("tank-image");

    Entity &chopperEntity(manager.AddEntity("Chopper"));
    chopperEntity.AddComponent<TransformComponent>(240.0f, 106.0f, 0.0f, 0.0f, 80.0f, 32.0f, 32.0f, 1.0f);
    chopperEntity.AddComponent<SpriteComponent>("chopper-image", 2, 0.1f, true, false);
    chopperEntity.AddComponent<KeyboardControlComponent>();

    Entity &radarEntity(manager.AddEntity("Radar"));
    radarEntity.AddComponent<TransformComponent>(720.0f, 15.0f, 0.0f, 0.0f, 0.0f, 64.0f, 64.0f, 1.0f);
    radarEntity.AddComponent<SpriteComponent>("radar-image", 8, 0.2f, false, true);
}

void Game::ProcessInput()
{
    // check all the window's events that were triggered since the last iteration of the loop
    sf::Event event;
    while (window->pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
        {
            isRunning = false;
            break;
        }
        case sf::Event::KeyPressed:
        {
            if (event.key.code == sf::Keyboard::Escape)
            {
                isRunning = false;
            }
            break;
        }
        default:
        {
            break;
        }
        }
    }
}

void Game::Update()
{
    sf::Time elapsed = clock.restart();
    float delta = elapsed.asSeconds();
    delta = (delta > 0.5f) ? 0.5f : delta;

    if (showFps)
        ShowFPS(delta);

    manager.Update(delta);
}

void Game::ShowFPS(float delta)
{
    if (fpsDelta >= 1.0)
    {
        std::cout << fps << std::endl;
        fpsDelta = 0.0;
        fps = 0;
    }

    fpsDelta += delta;
    fps++;
}

void Game::Render()
{
    // clear the window with black color
    window->clear(sf::Color(21, 21, 21, 255));

    // draw everything here...
    if (manager.HasEntities())
    {
        manager.Render(*window);
    }
    // end the current frame
    window->display();
}

void Game::Destroy()
{
    window->close();
    while (window->isOpen())
        ;
    delete window;
}
