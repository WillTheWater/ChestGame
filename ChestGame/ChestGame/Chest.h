#pragma once
#include "SFML/Graphics.hpp"
#include "Item.h"
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

private:
    std::vector<Item*> items[0];
};

