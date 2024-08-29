#include "Chest.h"
#include <random>
#include <iostream>

Chest::Chest()
{
    chestTexture.loadFromFile("assets/graphics/chest.png");
    chestSprite.setTexture(chestTexture);
    chestSprite.setTextureRect(sf::IntRect(0, 0, 50, 60));
    chestSprite.setPosition(SetRandomPosition());
    chestOpened = false;
}

void Chest::SpawnChest(sf::RenderWindow& gameWindow)
{
    sf::Vector2f mousePos = gameWindow.mapPixelToCoords(sf::Mouse::getPosition(gameWindow));
    
    gameWindow.draw(chestSprite);
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if (chestSprite.getGlobalBounds().contains(mousePos))
        {
            if (canOpenChest)
            {
                chestSprite.setTextureRect(sf::IntRect(50, 0, 50, 60));
                std::cout << "Chest is Opened!" << std::endl; 
                canOpenChest = false;
                chestOpened = true;// <-- where loot should spawn
                DropLoot();
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
    std::uniform_int_distribution<> xDist(xMin, xMax);
    std::uniform_int_distribution<> yDist(yMin, yMax);

    // Generate random x and y values within the specified ranges
    float x = xDist(gen);
    float y = yDist(gen);
    return sf::Vector2f{ x, y };
}

void Chest::DropLoot()
{
    if (chestOpened)
    {
        const int dropMin = 8;
        const int dropMax = 14;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dropDist(dropMin, dropMax);
        int numberOFDrops = dropDist(gen);
        
        std::cout << "Number of drops: " << numberOFDrops << std::endl;
    }
}


