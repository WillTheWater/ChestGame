#pragma once
#include "SFML/Graphics.hpp"
#include <vector>

class Chest
{
public:
    Chest();
    void                        SpawnChest(sf::RenderWindow& gameWindow);
    sf::Vector2f                SetRandomPosition();
    void                        DropLoot();
    

    sf::Texture                 chestTexture;
    sf::Sprite                  chestSprite;
    bool                        canOpenChest;
    bool                        chestOpened;
    std::vector<int> items;
};

