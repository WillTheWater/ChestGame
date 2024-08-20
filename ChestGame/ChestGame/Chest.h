#pragma once
#include "SFML/Graphics.hpp"
class Chest
{
public:
    Chest();
    ~Chest();

    void SpawnChest(sf::RenderWindow& gameWindow);
    sf::Vector2f SetRandomPosition();
    sf::Vector2f GetMousePos(sf::RenderWindow& gameWindow);

    sf::Texture chestTexture;
    sf::Sprite chestSprite;
    bool canOpenChest = true;
};