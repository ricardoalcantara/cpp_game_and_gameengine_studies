#ifndef TEXTLABELCOMPONENT_H
#define TEXTLABELCOMPONENT_H

#include <SFML/Graphics.hpp>
#include <string>
#include "Component.h"
#include "Game.h"

class TextLabelComponent : public Component
{
private:
    sf::Text text;

public:
    TextLabelComponent(int x, int y, std::string text, std::string fontFamily, const sf::Color &color)
    {
        this->text.setPosition(x, y);
        this->text.setString(text);
        this->text.setFont(*Game::assetManager->GetFont(fontFamily));
        this->text.setFillColor(color);
    }

    void Render(sf::RenderWindow &window) override
    {
        auto view = window.getView();
        window.setView(window.getDefaultView());
        window.draw(text);
        window.setView(view);
    }
};

#endif