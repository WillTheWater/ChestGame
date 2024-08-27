#pragma once
#include "SFML/Graphics.hpp"
class Chest
{
public:
    Chest();

    void                        SpawnChest(sf::RenderWindow& gameWindow);
    sf::Vector2f                SetRandomPosition();
    

    sf::Texture                 chestTexture;
    sf::Sprite                  chestSprite;
    bool                        canOpenChest;
};

