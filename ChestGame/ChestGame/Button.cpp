#include <iostream>
#include "Button.h"
Button::Button()
{
    buttonTexture.loadFromFile("assets/graphics/button.png");
    buttonSprite.setTexture(buttonTexture);
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
           //gameState = GameState::Playing;
        }
    }
    return false;
}
