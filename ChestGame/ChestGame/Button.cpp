#include <iostream>
#include "Button.h"
Button::Button()
{
    buttonTexture.loadFromFile("assets/graphics/button.png");
    buttonSprite.setTexture(buttonTexture);
    diabloFont.loadFromFile("assets/font/bolddiablo.ttf");
    buttonText.setFont(diabloFont);
    ButtonText("Start", 75);
}

Button::~Button()
{
}

void Button::DrawButton(sf::RenderWindow& gameWindow)
{
    gameWindow.draw(buttonSprite);
}

bool Button::StartGame(sf::RenderWindow& gameWindow)
{
    sf::Vector2f mousePos = gameWindow.mapPixelToCoords(sf::Mouse::getPosition(gameWindow));
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if (buttonSprite.getGlobalBounds().contains(mousePos))
        {
            std::cout << "Start Game" << std::endl;
            return true;
        }
    }
    return false;
}

void Button::ButtonText(const std::string& text, const unsigned int size)
{
    buttonText.setString(text);
    buttonText.setCharacterSize(size);
    buttonText.setFillColor(sf::Color::Black);
    buttonText.setPosition(100, 100);
    std::cout << "drawing text" << std::endl;
}
