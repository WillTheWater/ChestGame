#include "Chest.h"
#include "random"
#include <iostream>

Chest::Chest()
{
    chestTexture.loadFromFile("assets/graphics/chest.png");
    chestSprite.setTexture(chestTexture);
    chestSprite.setTextureRect(sf::IntRect(0, 0, 50, 60));
    chestSprite.setPosition(SetRandomPosition());
}

Chest::~Chest()
{
}

void Chest::SpawnChest(sf::RenderWindow& gameWindow)
{
    gameWindow.draw(chestSprite);
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if (chestSprite.getGlobalBounds().contains(GetMousePos(gameWindow)))
        {
            if (canOpenChest)
            {
                chestSprite.setTextureRect(sf::IntRect(50, 0, 50, 60));
                //std::cout << "Chest is Opened!" << std::endl;
                canOpenChest = false;
            }
            //else{ std::cout << "Chest is already Open!" << std::endl; }
        }
    }
}

sf::Vector2f Chest::SetRandomPosition()
{
    // Define the range for x and y
    const float xMin = 100.0f;
    const float xMax = 1820.0f;
    const float yMin = 100.0f;
    const float yMax = 980.0f;

    // Initialize random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> xDist(xMin, xMax);
    std::uniform_real_distribution<> yDist(yMin, yMax);

    // Generate random x and y values within the specified ranges
    float x = xDist(gen);
    float y = yDist(gen);
    return sf::Vector2f{ x, y };
}

sf::Vector2f Chest::GetMousePos(sf::RenderWindow& gameWindow)
{
    sf::Vector2f mousePos = gameWindow.mapPixelToCoords(sf::Mouse::getPosition(gameWindow));
    return mousePos;
}