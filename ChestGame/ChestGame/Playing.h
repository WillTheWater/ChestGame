#pragma once

#include "GameState.h"

class Playing : public GameState 
{
public:
    void HandleInput(sf::RenderWindow& window) override;
    void Update() override;
    void Draw(sf::RenderWindow& window) override;
};