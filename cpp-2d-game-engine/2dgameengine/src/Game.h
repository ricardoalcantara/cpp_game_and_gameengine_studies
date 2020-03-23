#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

class Game
{
    private:
        bool isRunning;
        sf::RenderWindow *window = nullptr;
        sf::Clock clock;
        float fps = 0;
        float fpsDelta = 0;
        bool lockFps = true;
        bool showFps = false;
    private:
        void Game::ShowFPS(float delta);
    public:
        Game();
        ~Game();
        bool IsRunning() const;
        void Initialize(int width, int height);
        void ProcessInput();
        void Update();
        void Render();
        void Destroy();
};

#endif