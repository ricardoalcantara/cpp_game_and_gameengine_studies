#include <iostream>
#include "Constants.h"
#include "Game.h"

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

// sf::RectangleShape shape(sf::Vector2f(10, 10));
void Game::Initialize(int width, int height)
{
    window = new sf::RenderWindow(sf::VideoMode(width, height), "My window");
    clock.restart();

    if (lockFps)
        window->setFramerateLimit(FPS);
    else
        window->setFramerateLimit(0);

    isRunning = true;

    // shape.setFillColor(sf::Color(255, 255, 255, 255));
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

// sf::Vector2f projectilePos;
// sf::Vector2f projectileVel(50, 50);

void Game::Update()
{
    sf::Time elapsed = clock.restart();
    float delta = elapsed.asSeconds();
    delta = (delta > 0.5f) ? 0.5f : delta;

    // projectilePos += projectileVel * delta;
    // shape.setPosition(projectilePos);

    if (showFps) ShowFPS(delta);
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
    // window->draw(...);
    // window->draw(shape);

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
